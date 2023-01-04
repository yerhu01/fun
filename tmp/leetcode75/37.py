class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            
        ptr1 = head
        ptr2 = slow.next
        slow.next = None # disconnect ptr1 from ptr2
        
        # reverse
        dummy = ListNode()
        while ptr2:
            dummy.next, ptr2.next, ptr2 = ptr2, dummy.next, ptr2.next
            
        # merge
        ptr1 = head.next
        ptr2 = dummy.next
        tail = head
        while ptr1 and ptr2:
            tail.next, ptr2 = ptr2, ptr2.next
            tail = tail.next
            tail.next, ptr1 = ptr1, ptr1.next
            tail = tail.next
        # for remainder, ptr2 should always be first to run out
        # put it here anyways
        tail.next = ptr1 or ptr2
