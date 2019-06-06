class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        return len([a for a, b in zip(heights, sorted(heights)) if a != b])
