class Solution:
    def trap(self, height: list[int]) -> int:

        leftMax = 0
        rightMax = 0
        ans = 0
        left = 0
        right = len(height)-1

        while left < right:

            if height[left] <= height[right]:

                if height[left] >= leftMax:
                    leftMax = height[left]
                else:
                    ans += leftMax - height[left]

                left += 1

            else:

                if height[right] >= rightMax:
                    rightMax = height[right]
                else:
                    ans += rightMax - height[right]

                right -= 1    

        return ans                        