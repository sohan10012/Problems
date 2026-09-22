class Solution:
    def maxProduct(self, nums: list[int]) -> int:
        
        maxProd = nums[0]
        minProd = nums[0]
        ans = nums[0]

        for i in range(1,len(nums)):

            oldm = maxProd
            oldmi = minProd

            maxProd = max({
                nums[i],
                oldm * nums[i],
                oldmi * nums[i]
            })

            minProd = min({
                nums[i],
                oldm * nums[i],
                oldmi * nums[i]
            })

            ans = max(ans,maxProd)

        return ans        