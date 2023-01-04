# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
import heapq

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        dummy = tail = ListNode()
        h = [(node.val, id(node), node) for node in lists if node]
        heapq.heapify(h)
        while h:
            _, _, node = heapq.heappop(h)
            tail.next = node
            tail = tail.next
            node = node.next
            if node:
                heapq.heappush(h, (node.val, id(node), node))
        return dummy.next
