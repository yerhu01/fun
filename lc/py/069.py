class Solution:
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        front = dummy = ListNode(0, head)
        for _ in range(left-1):
            front = front.next

        end = front.next
        for _ in range(right-left):
            tmp = end.next
            front.next, tmp.next, end.next = tmp, front.next, tmp.next

        return dummy.next
