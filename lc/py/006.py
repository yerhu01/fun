# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy = ListNode(0, head)
        fast, slow = dummy, dummy
        for _ in range(n):
            fast = fast.next

        while fast.next:
            fast, slow = fast.next, slow.next

        slow.next = slow.next.next
        return dummy.next
