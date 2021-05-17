void dfs(struct TreeNode* node) {
    if (node) {
        dfs(node->left);
        dfs(node->right);
        struct TreeNode *tmp = node->left;
        node->left = node->right;
        node->right = tmp;
    }
}

struct TreeNode* invertTree(struct TreeNode* root){
    dfs(root);
    return root;
}
