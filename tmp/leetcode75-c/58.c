/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode **resize_queue(struct TreeNode **q, int *mask, int *f, int *r) {
    int old_sz = *mask+1;
    *mask = (*mask << 1) + 1;
    if (*f < *r)
        return realloc(q, (*mask+1) * sizeof *q);
    else {
        struct TreeNode **tmp = malloc((*mask+1) * sizeof *tmp);
        int i = 0;
        for (int j = *f; j < old_sz; ++j, ++i)
            tmp[i] = q[j];
        for (int j = 0; j < *r; ++j, ++i)
            tmp[i] = q[j];
        *f = 0; *r = i;
        free(q);
        return tmp;
    }
}

struct TreeNode *new_node(int val) {
    struct TreeNode *node = malloc(sizeof *node);
    memset(node, 0, sizeof *node);
    node->val = val;
    return node;
}
    
/** Encodes a tree to a single string. */
char* serialize(struct TreeNode* root) {
    if (!root)
        return "n";
    
    int ret_mask = 0xFF, curr = 0;
    char *ret = malloc((ret_mask+1) * sizeof *ret);
    
    int q_mask = 0xFF, f = 0, r = 0; // Circular queue
    struct TreeNode **q = malloc((q_mask+1) * sizeof *q);
    
    q[r++] = root;
    while (r-f & q_mask) { // len > 0
        struct TreeNode *node = q[f++ & q_mask];
        if (!node)
            curr += sprintf(&ret[curr], "n,");
        else {
            curr += sprintf(&ret[curr], "%d,", node->val);
            q[r++ & q_mask] = node->left;
            q[r++ & q_mask] = node->right;
        }
        f &= q_mask; r &= q_mask;
        
        // Resize if necessary
        if (curr+6 >= ret_mask+1) {
            ret_mask = (ret_mask << 1) + 1;
            ret = realloc(ret, (ret_mask+1) * sizeof *ret);
        }
        if ((r-f & q_mask) >= q_mask)
            q = resize_queue(q, &q_mask, &f, &r);
    }
    free(q);
    return ret;
}

/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data) {
    if (!data || data[0] == 'n')
        return NULL;
    
    char *token = strtok(data, ",");
    struct TreeNode *root = malloc(sizeof *root);
    memset(root, 0, sizeof *root);
    root->val = atoi(token);
    
    int q_mask = 0xFF, f = 0, r = 0;
    struct TreeNode **q = malloc((q_mask+1) * sizeof *q);
    
    q[r++] = root;
    while (r-f & q_mask) {
        struct TreeNode *node = q[f++ & q_mask];
        
        token = strtok(NULL, ",");
        if (strcmp(token, "n") != 0) {
            node->left = new_node(atoi(token));
            q[r++ & q_mask] = node->left;
        }
        
        token = strtok(NULL, ",");
        if (strcmp(token, "n") != 0) {
            node->right = new_node(atoi(token));
            q[r++ & q_mask] = node->right;
        }
        f &= q_mask; r &= q_mask;
        
        //Resize if necessary
        if ((r-f & q_mask) >= q_mask)
            q = resize_queue(q, &q_mask, &f, &r);
    }
    free(q);
    return root;
}


// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);
