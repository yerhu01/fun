class Solution:
    def minWindow(self, s: str, t: str) -> str:
        cnt = Counter(t)
        total = len(t)
        min_len = float('inf')
        start, end = 0, 0
        l = 0
        for r, c in enumerate(s):
            if c in cnt:
                cnt[c] -= 1
                if cnt[c] >= 0:
                    total -= 1

            while total == 0:
                if s[l] in cnt:
                    if r-l+1 < min_len:
                        min_len = r-l+1
                        start, end = l, r
                    cnt[s[l]] += 1
                    if cnt[s[l]] > 0:
                        total += 1
                l += 1
        return s[start:end+1] if min_len < float('inf') else ""
