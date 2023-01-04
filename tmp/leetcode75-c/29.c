#define MASK 0x1FFF

struct TreeNode *create_tree(int *preorder,  int *preorder_idx, int *inorder_map,
                            int left, int right) {
    if (left > right)
        return NULL;

    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = preorder[*preorder_idx];
    *preorder_idx += 1;
    root->left = create_tree(preorder, preorder_idx, inorder_map, left, inorder_map[root->val & MASK]-1);
    root->right = create_tree(preorder, preorder_idx, inorder_map, inorder_map[root->val & MASK]+1, right);
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    int preorder_idx = 0;
    int inorder_map[MASK+1] = {0};
    for (int i = 0; i < inorderSize; ++i) {
        inorder_map[inorder[i] & MASK] = i;
    }

    return create_tree(preorder, &preorder_idx, inorder_map, 0, inorderSize-1);
}

#undef MASK
