# Cleaner
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = tail = ListNode()
        carry = 0
        while l1 or l2 or carry:
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0
            carry, val = divmod(val1 + val2 + carry, 10)
            tail.next = ListNode(val)
            tail = tail.next
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        return dummy.next

# My solution
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = tail = ListNode()
        carry = 0
        while l1 and l2:
            val = l1.val + l2.val + carry
            tail.next = ListNode(val%10)
            carry = val // 10
            tail, l1, l2 = tail.next, l1.next, l2.next
        
        l1 = l1 or l2
        while l1:
            val = l1.val + carry
            tail.next = ListNode(val%10)
            carry = val // 10
            tail, l1 = tail.next, l1.next
            
        if carry:
            tail.next = ListNode(carry)
        return dummy.next
    
    
''' CASES:
 2 4 3 + 5 6 4 = 7 0 8
 2 4 5 + 5 6 4 = 7 0 0 1
 9 9 9 9 + 9 9 = 8 9 0 0 1
'''
