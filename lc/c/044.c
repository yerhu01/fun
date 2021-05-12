struct ListNode* reverseList(struct ListNode* head){
    struct ListNode dummy = {0};
    while (head) {
        struct ListNode *tmp = head->next;
        head->next = dummy.next;
        dummy.next = head;
        head = tmp;
    }
    return dummy.next;
}
