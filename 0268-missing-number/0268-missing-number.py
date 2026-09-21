class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        ans = len(nums)

        for i in range(len(nums)):
            ans ^= i
            ans ^= nums[i]

        return ans