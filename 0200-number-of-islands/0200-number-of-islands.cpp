class Solution {
public:

    void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>>& grid, int n, int m){
        if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] != '1' ){
            return;
        }

        vis[i][j] = true;
        //then visit the neighbours
        dfs(i-1, j, vis, grid, n, m); //top
        dfs(i, j+1, vis, grid, n, m); //right
        dfs(i+1, j, vis, grid, n, m); //bottom
        dfs(i, j-1, vis, grid, n, m); //left
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                //if not visited and grid[i][j] == 1
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(i,j,vis,grid,n,m); //   1 component is visited
                    islands++;
                }
            }
        }
        return islands;
    }
};