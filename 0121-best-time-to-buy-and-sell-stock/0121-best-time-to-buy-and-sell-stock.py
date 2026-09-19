class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        
        maxp = 0
        minv = prices[0]


        for i in range(1,len(prices)):

            minv = min(minv,prices[i])
            
            profit = prices[i] - minv

            maxp = max(profit,maxp)

        return maxp    

