typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
private:
    int rec(vvi& grid, int i, int j){
        if(i == 0 && j == 0) return grid[i][j];
        
        int left = (j > 0) ? rec(grid, i, j-1) : INT_MAX;
        int up = (i > 0) ? rec(grid, i-1, j) : INT_MAX;

        return(min(left, up) + grid[i][j]);
    }
    int memoiz(vvi& grid, vvi& memo, int i, int j){
        if(i == 0 && j == 0) return grid[0][0];
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        int left = (j > 0) ? memoiz(grid, memo, i, j-1) : INT_MAX;
        int up = (i > 0) ? memoiz(grid, memo, i-1, j) : INT_MAX;

        return(memo[i][j] = min(left, up) + grid[i][j]);
    }
    int memoization(vvi& grid, int m, int n){
        vvi memo(m, vi(n, -1));
        return memoiz(grid, memo, m-1, n-1);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //return rec(grid, m-1, n-1);
        return memoization(grid, m, n);
    }
};