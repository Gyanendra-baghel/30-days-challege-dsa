class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        f0 = sum([i*num for i, num in enumerate(nums)])
        total_sum, size = sum(nums), len(nums)

        max_fn, prev_fn = f0, f0

        for i in range(size-1, 0, -1):
            num = nums[i]
            next_fn = prev_fn + total_sum - size*(num)
            max_fn = max(max_fn, next_fn)

            prev_fn = next_fn

        return max_fn