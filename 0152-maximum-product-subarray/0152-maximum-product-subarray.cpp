class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxProd = nums[0];
        int minProd = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            int oldMax = maxProd;
            int oldMin = minProd;

            maxProd = max({
                nums[i],
                oldMax * nums[i],
                oldMin * nums[i]
            });

            minProd = min({
                nums[i],
                oldMax * nums[i],
                oldMin * nums[i]
            });

            ans = max(ans, maxProd);
        }

        return ans;
    }
};