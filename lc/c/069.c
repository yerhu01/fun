struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    struct ListNode dummy = {.next = head}, *front = &dummy;
    for (int i = 0; i < left-1; ++i)
        front = front->next;

    struct ListNode *end = front->next;
    for (int i = 0; i < right-left; ++i){
        struct ListNode *tmp1 = front->next;
        struct ListNode *tmp2 = end->next->next;
        front->next = end->next;
        front->next->next = tmp1;
        end->next = tmp2;
    }
    return dummy.next;
}
