/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool same(struct TreeNode *p, struct TreeNode *q) {
    if (!p && !q)
        return true;
    else if (!p || !q)
        return false;
    else if (p->val != q->val)
        return false;
    return same(p->left, q->left) && same(p->right, q->right);
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    return same(p, q);
}
