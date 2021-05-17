int inorder(struct TreeNode *node, int *k) {
    if (!node)
        return -1;

    int ret = inorder(node->left, k);
    if (ret != -1)
        return ret;

    *k -= 1;
    if (*k == 0)
        return node->val;

    ret = inorder(node->right, k);
    if (ret != -1)
        return ret;

    return -1;
}

int kthSmallest(struct TreeNode* root, int k){
    return inorder(root, &k);
}
