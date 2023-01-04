'''

CCCAAAA k=3 => 7
    k left over go back

ABBAAAA k=1 => 5

ABBAABBBBB k=2 => 9
ABCAABBBBB

ALgorithm: 2 pointers
'''

class Solution:
    # Sliding Window O(n) time O(n) space
    def characterReplacement(self, s: str, k: int) -> int:
        ret = 0
        cnt = defaultdict(int)
        max_cnt = 0
        l = 0
        for r in range(len(s)):
            cnt[s[r]] += 1
            max_cnt = max(max_cnt, cnt[s[r]])
            
            if r-l+1-max_cnt > k:
                cnt[s[l]] -= 1
                l += 1
            else:
                ret = max(ret, r-l+1)
        return ret

    # O(n^2) Bruteforce
    def characterReplacement(self, s: str, k: int) -> int:
        ret = 0
        count = k
        l, r = 0, 0
        while r < len(s):
            if s[r] != s[l]:
                count -= 1
                if count == -1:
                    count = k
                    ret = max(ret, r-l)
                    l += 1; r = l
            r += 1

        while l > 0 and count > 0:
            count -= 1
            l -= 1    
        ret = max(ret, r-l)
        return ret
