class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        if(target > nums[n-1]){
            return n;
        }

        if(target < nums[0]){
            return 0;
        }

        for(int i = 0 ; i < n ; i++){
            if(nums[i] >= target){
                return i;
            }
        }

        return 1;
    }
};