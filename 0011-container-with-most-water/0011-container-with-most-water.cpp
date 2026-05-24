class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int maxa = 0;
        int i  = 0;
        int j = height.size() -1;

        while( i < j ){

            int minv = min(height[i] , height[j]);

            int area = minv * (j-i);

            maxa = max(maxa,area);

            if(height[i] < height[j]){
                i++;
            }
            else{
                j--;
            }

        }

        return maxa;
        
    }
};