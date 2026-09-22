class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });


        int pe = intervals[0][1];
        int re = 0;

        for(int i = 1 ; i < intervals.size() ; i++){

            int start = intervals[i][0];
            int end = intervals[i][1];

            if(start < pe){
                re++;
            }
            else{
                pe = end;
            }

        }

        return re;

    }
};