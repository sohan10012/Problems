class Solution {
public:

void visited(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& vis, int n, int m){
    
    if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || grid[i][j] == '0'){
        return;
    }

    vis[i][j] = true;

    visited(i-1,j,grid,vis,n,m);
    visited(i+1,j,grid,vis,n,m);
    visited(i,j-1,grid,vis,n,m);
    visited(i,j+1,grid,vis,n,m);
}

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int island = 0;

        vector<vector<bool>> vis(n,vector<bool>(m,false));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j < m ; j++){
                if( grid[i][j] == '1' && !vis[i][j]){
                    visited(i,j,grid,vis,n,m);
                    island++;
                }
            }
        }
        return island;
    }
};