// Iterative
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    while (root) {
        if (root->val < p->val && root->val < q->val)
            root = root->right;
        else if (root->val > p->val && root->val > q->val)
            root = root->left;
        else
            return root;
    }
    return NULL; // Unreachable
}

// Recursive
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root->val < p->val && root->val < q->val)
        return lowestCommonAncestor(root->right, p, q);
    else if (root->val > p->val && root->val > q->val)
        return lowestCommonAncestor(root->left, p, q);
    else
        return root;
}
