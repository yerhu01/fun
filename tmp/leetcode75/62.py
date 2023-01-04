# My heap 2
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        if k == len(nums):
            return nums
        
        min_heap = []
        c = Counter(nums)
        items = iter(c.items())
        for _ in range(k): # heap stores k items
            num, freq = next(items)
            heapq.heappush(min_heap, (freq, num)) # klogk
        # NOTE: since heap is storing top k items, using min heap
            
        for num, freq in items:
            heapq.heappushpop(min_heap, (freq, num)) # Nlogk
        
        return [ item[1] for item in min_heap]
        #return [ item[1] for item in heapq.nlargest(k, min_heap)]

# My heap 1
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        max_heap = []
        c = Counter(nums) # O(N)
        for num, freq in c.items(): # O(N)
            heapq.heappush(max_heap, (-freq, num)) # O(Nlogk)
            
        ret = []
        for _ in range(k):
            ret.append(heapq.heappop(max_heap)[1]) # O(klogk)
        return ret

# Heap
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        if k == len(nums):
            return nums
        
        c = Counter(nums) 
        return heapq.nlargest(k, c.keys(), key=c.get)

# Counter API
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        if k == len(nums):
            return nums
        
        return [x for x, y in collections.Counter(nums).most_common(k)]
