class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int totalSum = 0;
        

        for(int n : nums){
            totalSum += n;
        }

        int lsum = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            int rsum = totalSum - lsum - nums[i];

            if(lsum == rsum){
                return i;
            }

            lsum += nums[i];
        }
        return -1;
    }
};