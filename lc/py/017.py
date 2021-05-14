# Heap
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        ret = []
        heapq.heapify(intervals)
        curr = heapq.heappop(intervals)
        while intervals:
            nxt = heapq.heappop(intervals)
            if curr[1] < nxt[0]:
                ret.append(curr)
                curr = nxt
            else:
                curr[1] = max(curr[1], nxt[1])
        ret.append(curr)
        return ret

# Sorting
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        ret = []
        intervals.sort()
        curr = intervals[0]
        for i in range(1, len(intervals)):
            if curr[1] < intervals[i][0]:
                ret.append(curr)
                curr = intervals[i]
            else:
                curr[1] = max(curr[1], intervals[i][1])
        ret.append(curr)
        return ret
