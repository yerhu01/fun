class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def dfs(combo, total, index):
            if total == target:
                ret.append(combo[:])
                return

            for i in range(index, len(candidates)):
                if total+candidates[i] > target:
                    return
                combo.append(candidates[i])
                dfs(combo, total+candidates[i], i)
                combo.pop()

        ret = []
        candidates.sort()
        dfs([], 0, 0)
        return ret

# slow
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def dfs(combo, total, index):
            if total > target:
                return
            elif total == target:
                ret.append(combo[:])
                return

            for i in range(index, len(candidates)):
                combo.append(candidates[i])
                dfs(combo, total+candidates[i], i)
                combo.pop()

        ret = []
        dfs([], 0, 0)
        return ret

# subtract target
def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []

        def dfs(combo, total, index):
            if total == 0:
                result.append(combo[:])
                return
            for i in range(index, len(candidates)):
                if total - candidates[i] < 0:
                    return
                combo.append(candidates[i])
                dfs(combo, total-candidates[i], i)
                combo.pop()

        candidates.sort()
        dfs([], target, 0)
        return result

# slow
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        def dfs(total, index):
            if total == 0:
                result.append(combo[:])
            elif total > 0:
                for i in range(index, len(candidates)):
                    combo.append(candidates[i])
                    dfs(total-candidates[i], i)
                    combo.pop()

        candidates.sort()
        combo = []
        dfs(target, 0)
        return result
