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
    int helper1(vvi& grid, vvi& dp, int m, int n){
        dp[0][0] = grid[0][0];

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) continue;
                int left = (j > 0) ? dp[i][j-1] : INT_MAX;
                int up = (i > 0) ? dp[i-1][j] : INT_MAX;
                dp[i][j] = min(left, up) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
    int tabulation(vvi& grid, int m, int n){
        if(m == 0 && n == 0) return grid[m][n];
        vvi dp(m, vi(n));
        return helper1(grid, dp, m, n);
    }
    //To compute row i, you only need:
    // the current row (for the left value), and
    // the previous row (for the up value).
    int space_opt(vvi& grid, int m, int n){
        //prev[j] = minimum path sum to reach row 0, column j
        vi prev(n);
        prev[0] = grid[0][0]; //top-left cell
        for(int i = 1; i < n; i++){
            prev[i] = prev[i-1] + grid[0][i]; //prefix-sum
            //for the first row, prev = [1,4,5]
        }
        for(int i = 1; i < m; i++){
            //curr represents the DP values of the current row, for every new row
            vi curr(n);
            for(int j = 0; j < n; j++){
                int left = (j > 0) ? curr[j-1] : INT_MAX;
                int up = (i > 0) ? prev[j] : INT_MAX;
                curr[j] = min(left, up) +  grid[i][j];
            }
            prev = curr;
        }
        return prev[n-1];
    }
    int single_vector(vvi &grid) {
        int m = grid.size(), n = grid[0].size();
        vi prev(n);
        prev[0] = grid[0][0];
        for(int i = 1; i < n; i++) {
            prev[i] = prev[i-1] + grid[0][i];
        }

        for(int i = 1; i < m; i++) {
            prev[0] += grid[i][0];
            for(int j = 1; j < n; j++) {
                prev[j] = min(prev[j-1], prev[j]) + grid[i][j];
            }
        }
        return prev[n-1];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        //int m = grid.size();
        //int n = grid[0].size();
        //return rec(grid, m-1, n-1);
        return single_vector(grid);
    }
};

//T.C. = O(m x n)