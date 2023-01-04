'''
After sorting...
CASE 0: Non overlapping
[1,2] [2,3] [3,4] => 1

CASE 1: Continuous chain
[1,3] [2,4] [3,5] [4,5] => 2, remove alternating

CASE 2: Big interval, with many inside
[  [] [] [] []  ] => 1 remove outer interval
[1,10] [2,3] [3,4] [4,5] => 1

Case 3: Big interval with continuous chain inside
[1,10] [2,4] [3,5] [4,6] => 2 (remove outer interval and linking intervals)
'''
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        if len(intervals):
            return 0
        
        ret = 0
        intervals.sort()
        curr = 0
        for i in range(1,len(intervals)):
            if intervals[curr][1] <= intervals[i][0]: # Non overlapping
                curr = i
            elif intervals[curr][1] > intervals[i][0] and intervals[curr][1] < intervals[i][1]: # Chain
                ret += 1
            else: # Outer overlapping
                curr = i
                ret += 1

        return ret

    # Alternative solution
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        if len(intervals) <= 1: 
            return 0
        
        intervals.sort(key = lambda x: x[1])
        non_overlap = 1
        curr = 0
        for i in range(1, len(intervals)):
            if intervals[i][0] >= intervals[curr][1]:
                curr = i
                non_overlap += 1
        
        return len(intervals) - non_overlap
