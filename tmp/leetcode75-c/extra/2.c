struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode dummy = { .val = 0, .next = NULL };
    struct ListNode *tail = &dummy;
    int val1, val2, val;
    int carry = 0;
    while (l1 || l2 || carry) {
        val1 = (l1) ? l1->val : 0;
        val2 = (l2) ? l2->val : 0;
        val = val1 + val2 + carry;
        carry = val / 10;
        
        tail->next = malloc(sizeof(struct ListNode));
        tail = tail->next;
        tail->val = val%10;
        tail->next = NULL;
        
        l1 = (l1) ? l1->next : NULL;
        l2 = (l2) ? l2->next: NULL;
    }
    return dummy.next;
}
