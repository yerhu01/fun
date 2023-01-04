'''
heaps:
less = max heap
greater = min heap

addnum:
if len(less) > len(greater):
    if num <= median (less)
        add to less
        remove from less, add to greater
    if num > median (less)
        add to greater
if len(greater) > len(less):
    if num <= median (greater)
        add to less
    if num > median (greater)
        add to greater
        remove from greater, add to less
elif len(less) == len(greater):


findmedian:
if len(less) == len(greater):
    average of top of both
elif len(less) > len(greater):
    top of less
else
    top of greater
'''
import heapq

class MedianFinder:

    def __init__(self):
        self.less = [] # max heap
        self.greater = [] # min heap

    def addNum(self, num: int) -> None:
        heapq.heappush(self.less, -num)
        heapq.heappush(self.greater, -heapq.heappop(self.less))
        # Ensure that less is >= greater by 1
        if len(self.less) < len(self.greater):
            heapq.heappush(self.less, -heapq.heappop(self.greater))

    def findMedian(self) -> float:
        if len(self.less) == len(self.greater):
            return (-self.less[0] + self.greater[0])/2
        elif len(self.less) > len(self.greater):
            return -self.less[0]

# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
