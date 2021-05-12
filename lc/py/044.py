class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        dummy = ListNode()
        while head:
            dummy.next, head.next, head = head, dummy.next, head.next
        return dummy.next
