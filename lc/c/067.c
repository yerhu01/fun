bool sameTree(struct TreeNode *s, struct TreeNode *t) {
    if (!s && !t)
        return true;
    else if (!s || !t)
        return false;
    else if (s->val != t->val)
        return false;
    return sameTree(s->left, t->left) && sameTree(s->right, t->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t){
    if (!s)
        return false;
    else if (s->val == t->val && sameTree(s, t))
        return true;
    return isSubtree(s->left, t) || isSubtree(s->right, t);
}
