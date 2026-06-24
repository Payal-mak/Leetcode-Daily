typedef vector<int> vi;
typedef vector<vi> vvi;

#define forn(i,n) for(int i = 0; i < n; i++)

class Solution {
private:
    int rec(vvi &grid, int i, int j) {
        if (i==0 && j==0) { return grid[i][j]; }

        int left = (j > 0) ? rec(grid, i, j-1) : INT_MAX;
        int up = (i > 0) ? rec(grid, i-1, j) : INT_MAX;
        return min(left, up) + grid[i][j];
    }
    int helper(vvi &grid, int i, int j, vvi &memo) {
        if (memo[i][j] != -1) { return memo[i][j]; }
        int left = (j > 0) ? helper(grid, i, j-1, memo) : INT_MAX;
        int up = (i > 0) ? helper(grid, i-1, j, memo) : INT_MAX;
        return (memo[i][j] = min(left, up) + grid[i][j]);

    }
    int memoization(vvi &grid) {
        int m = grid.size(), n = grid[0].size();
        vvi memo(m, vi(n, -1));
        memo[0][0] = grid[0][0];
        return helper(grid, m-1, n-1, memo);
    }
    int tabulation(vvi &grid){
        int m = grid.size(), n = grid[0].size();
        vvi dp(m, vi(n));
        dp[0][0] = grid[0][0];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (i==0 & j==0) { continue; }
                int left = (j > 0) ? dp[i][j-1] : INT_MAX;
                int up = (i > 0) ? dp[i-1][j] : INT_MAX;
                dp[i][j] = min(left, up) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
    int space_optimization(vvi &grid) {
        int m = grid.size(), n = grid[0].size();
        vi prev(n);
        prev[0] = grid[0][0];
        for(int i = 1; i < n; i++) {
            prev[i] = prev[i-1] + grid[0][i];
        }

        for(int i = 1; i < m; i++) {
            vi curr(n);
            for(int j = 0; j < n; j++) {
                int left = (j > 0) ? curr[j-1] : INT_MAX;
                int up = (i > 0) ? prev[j] : INT_MAX;
                curr[j] = min(left, up) + grid[i][j];
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
        // return rec(grid, m-1, n-1);
        return single_vector(grid);
    }
};