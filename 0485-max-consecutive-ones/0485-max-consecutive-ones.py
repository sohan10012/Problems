class Solution:
    def findMaxConsecutiveOnes(self, nums: list[int]) -> int:
        vmax = 0
        c = 0

        for i in range(len(nums)):
            if nums[i] == 1:
                c += 1
                vmax = max(vmax, c)
            else:
                c = 0

        return vmax