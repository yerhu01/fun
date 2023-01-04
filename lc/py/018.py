class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        ret = []
        for interval in intervals:
            if interval[1] < newInterval[0]:
                ret.append(interval)
            elif interval[0] > newInterval[1]:
                ret.append(newInterval)
                newInterval = interval
            else:
                newInterval[0] = min(interval[0], newInterval[0])
                newInterval[1] = max(interval[1], newInterval[1])
        ret.append(newInterval)
        return ret
