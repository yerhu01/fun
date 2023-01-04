/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// MY OWN HASH TABLE (PYTHON DICT)
#define EMPTY 0

struct node {
    char *key; // sorted string
    char **anagrams; // array of strings
    int i; //next position of anagrams array
    int size; //size of anagrams array
};

unsigned long djb2(unsigned char *str) {
    unsigned long hash = 5381;
    int c;
    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    
    return hash;
}

int lookup (struct node **htable, int mask, char *str) {
    unsigned long hash = djb2(str);
    int h = hash & mask;
    unsigned long perturb = hash;
    
    for (;;) {
        if (htable[h] == EMPTY || strcmp(htable[h]->key, str) == 0)
            return h;
        
        // Handle collisions
        perturb >>= 5;
        h = (5*h + 1 + perturb) & mask;
    }
}

static int compare(const void *a, const void *b) {
    return *(char*)a - *(char*)b; 
}

int hmask(int x) {
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x;
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    int mask = hmask(strsSize);
    struct node *htable[mask+1]; // array of node pointers
    memset(htable, 0, (mask+1) * sizeof(struct node*)); // set pointers null
    *returnSize = 0;
    
    char sorted[strsSize][101];
    for (int i = 0; i < strsSize; ++i) {
        strcpy(sorted[i], strs[i]);
        qsort(sorted[i], strlen(sorted[i]), sizeof(char), compare);
    }
    
    for (int i = 0; i < strsSize; ++i) {
        int h = lookup(htable, mask, sorted[i]);
        if (htable[h]) {
            if (htable[h]->i == htable[h]->size) { // resize
                htable[h]->size *= 2;
                htable[h]->anagrams = realloc(htable[h]->anagrams, htable[h]->size * sizeof(char*));
            }
            htable[h]->anagrams[htable[h]->i++] = strs[i];
        } else {
            // insert new entry
            htable[h] = malloc(sizeof(struct node));
            htable[h]->key = sorted[i];
            htable[h]->size = 3;
            htable[h]->i = 0;
            htable[h]->anagrams = malloc(htable[h]->size * sizeof(char*));
            htable[h]->anagrams[htable[h]->i++] = strs[i];
            *returnSize += 1;
        }
    }   

    *returnColumnSizes = malloc((*returnSize) * sizeof(int));
    char ***ret = malloc((*returnSize) * sizeof(char**)); // array of array of strings
    for (int i = 0, j = 0; i < mask+1; ++i) {
        if (htable[i]) {
            ret[j] = htable[i]->anagrams;
            (*returnColumnSizes)[j] = htable[i]->i;
            j++;
            free(htable[i]);
        }
    }
    return ret;
}

// MY OWN HASH TABLE (LINKED LISTS COLLISION)
unsigned long shash(unsigned char *str) {
    unsigned long hash = 5381;
    int c;
    
    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    
    return hash;
}

static int compare(const void *a, const void *b) {
    return *(char*)a - *(char*)b; 
}

struct node {
    char *key; // sorted string
    char **anagrams; // array of strings
    int i; //next position of anagrams array
    int size; //size of anagrams array
    struct node *next; // collisions
};

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    int hsize = strsSize*1.3;
    struct node *htable[hsize]; // array of node pointers
    memset(htable, 0, hsize*sizeof(struct node*)); // set pointers null
    *returnSize = 0;
    
    char sorted[strsSize][101];
    for (int i = 0; i < strsSize; ++i) {
        strcpy(sorted[i], strs[i]);
        qsort(sorted[i], strlen(sorted[i]), sizeof(char), compare);
    }
    
    for (int i = 0; i < strsSize; ++i) {
        int h = shash(sorted[i]) % hsize;
        if (htable[h]) {
            struct node *ptr = htable[h];
            while (ptr->next && strcmp(ptr->key, sorted[i]) != 0) {
                // collision
                ptr = ptr->next;
            }
            
            if (strcmp(ptr->key, sorted[i]) == 0) {
                //found node
                if (ptr->i == ptr->size) {
                    ptr->size *= 2;
                    ptr->anagrams = realloc(ptr->anagrams, ptr->size * sizeof(char*));
                }
                ptr->anagrams[ptr->i++] = strs[i];
            } else {
                // new node at end of list
                ptr->next = malloc(sizeof(struct node));
                ptr = ptr->next;
                ptr->key = sorted[i];
                ptr->size = 3;
                ptr->i = 0;
                ptr->anagrams = malloc(ptr->size * sizeof(char*));
                ptr->anagrams[ptr->i++] = strs[i];
                ptr->next = NULL;
                *returnSize += 1;
            }
        } else {
            // insert new entry
            htable[h] = malloc(sizeof(struct node));
            htable[h]->key = sorted[i];
            htable[h]->size = 3;
            htable[h]->i = 0;
            htable[h]->anagrams = malloc(htable[h]->size * sizeof(char*));
            htable[h]->anagrams[htable[h]->i++] = strs[i];
            htable[h]->next = NULL;
            *returnSize += 1;
        }
    }   

    *returnColumnSizes = malloc((*returnSize) * sizeof(int));
    char ***ret = malloc((*returnSize) * sizeof(char**)); // array of array of strings
    for (int i = 0, j = 0; i < hsize; ++i) {
        if (htable[i]) {
            struct node *ptr = htable[i];
            while (ptr) {
                ret[j] = ptr->anagrams;
                (*returnColumnSizes)[j] = ptr->i;
                j++;
                struct node *tmp = ptr;
                ptr = ptr->next;
                free(tmp);
            }
        }
    }
    return ret;
}


// UT HASH 
struct hash {
    char *key; // sorted string
    char **anagrams; // array of strings
    int i; //next pos of anagrams array
    int size; //size of anagrams array
    UT_hash_handle hh;
};

static int compare(const void *a, const void *b) {
    return *(char*)a - *(char*)b; 
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    struct hash *htable = NULL, *h, *tmp;
    char sorted[strsSize][101];
    for (int i = 0; i < strsSize; ++i) {
        strcpy(sorted[i], strs[i]);
        qsort(sorted[i], strlen(sorted[i]), sizeof(char), compare);
    }
    
    for (int i = 0; i < strsSize; ++i) {
        HASH_FIND_STR(htable, sorted[i], h);
        if (h) {
            // Append str to end of list
            if (h->i == h->size) {
                h->size *= 2;
                h->anagrams = realloc(h->anagrams, h->size * sizeof(char*));
            }
            h->anagrams[h->i] = malloc((strlen(strs[i])+1) * sizeof(char));
            strcpy(h->anagrams[h->i], strs[i]);
            h->i++;
        } else {
            //insert new hash entry
            h = malloc(sizeof(struct hash));
            h->key = sorted[i];
            h->size = 3;
            h->anagrams = malloc(h->size * sizeof(char*));
            h->i = 0;
            h->anagrams[h->i] = malloc((strlen(strs[i])+1) * sizeof(char));
            strcpy(h->anagrams[h->i], strs[i]);
            h->i++;
            HASH_ADD_STR(htable, key, h);
        }
    }   
    
    *returnSize = HASH_COUNT(htable);
    *returnColumnSizes = malloc((*returnSize) * sizeof(int));
    char ***ret = malloc((*returnSize) * sizeof(char**));
    int i = 0;
    HASH_ITER(hh, htable, h, tmp) {
        ret[i] = h->anagrams;
        (*returnColumnSizes)[i] = h->i;
        i++;
        free(h);
    }
    return ret;
}

// Inside HASH_ITER to print anagram lists:
//for (int i = 0; i < h->i; ++i) {
//    puts(h->anagrams[i]);
//}
//printf("\n");
  
// Instead of strcpy (but slower)
//*h->anagrams[h->i] = '\0';
//strcat(h->anagrams[h->i], strs[i]);
