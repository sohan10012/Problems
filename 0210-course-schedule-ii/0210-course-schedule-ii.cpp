class Solution {
public:

    bool isCycle(int src,vector<int>& vis,vector<int>& recPath, vector<vector<int>>& p, vector<int>& ans){
        vis[src] = true;
        recPath[src] = true;

        for(int i = 0 ; i < p.size() ; i++){

            int v = p[i][0];
            int u = p[i][1];

            if(u == src){
                if(!vis[v]){
                    if(isCycle(v, vis, recPath, p, ans)){
                        return true;
                    }
                }
                else if(recPath[v]){
                    return true;
                }
            }
            
        }
        recPath[src] = false;
        return false;
    }

    void topSor(int src, vector<int>& vis, stack<int>& s, vector<vector<int>>& p){
        vis[src] = true;

        for(int i = 0 ; i < p.size() ; i++){

            int v = p[i][0];
            int u = p[i][1];

            if(u == src){
                if(!vis[v]){
                    topSor(v,vis,s,p);
                }
                
            }
            
        }
        s.push(src);
    }

    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> vis(n,false);
        vector<int> recPath(n,false);
        vector<int> ans;

        for(int i = 0 ; i < n ;  i++){
            if(!vis[i]){
                if(isCycle(i,vis,recPath,p,ans)){
                    return ans;
                }
            }
        }
        stack<int> s;
        vis.assign(n,false);

        for(int i = 0 ; i < n ;  i++){
            if(!vis[i]){
                topSor(i,vis,s,p);
            }
        }

        while(s.size() > 0){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};