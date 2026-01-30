class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> s;
        int n = h.size();
        vector<int> l(n) , r(n);

        //NGE
        for(int i = n-1 ; i>= 0 ; i--){
            while(!s.empty() && h[s.top()] >= h[i]){
                s.pop();
            }

            r[i] = s.empty() ? n : s.top();

            s.push(i);
        }

        while(!s.empty()) s.pop();

        //PSE
        for(int i = 0 ; i<n ; i++){
            while(!s.empty() && h[s.top()] >= h[i]){
                s.pop();
            }

            l[i] = s.empty() ? -1 : s.top();

            s.push(i);
        }

        int maxarea = 0;
        for (int i = 0; i < n; i++) 
        {
        int width = r[i] - l[i] - 1;
        maxarea = max(maxarea, h[i] * width);
        }

        return maxarea;

    }
};