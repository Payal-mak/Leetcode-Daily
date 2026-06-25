class Solution {
public:
    int rec(int n){
        //base cases
        if(n == 1) return 1;
        if(n == 2) return 2;

        //rec function
        return rec(n-1) + rec(n-2);
    }

    int memoiz(vector<int>& memo, int i){
        //check if a value is already computed before
        if(memo[i] != -1){
            return memo[i];
        }
        //store the computed result in the memo
        return (memo[i] = memoiz(memo, i-1) + memoiz(memo, i-2));
    }
    int memoization(int n){
        //base cases
        if(n == 1) return 1;
        if(n == 2) return 2;
        vector<int> memo(n,-1);
        //identify repeated steps
        memo[0] = 1;
        memo[1] = 2;
        return memoiz(memo, n-1);
    }

    int solve_dp(vector<int>& dp, int n){
        for(int i = 2; i < n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n-1];
    }

    int tabulation(int n){
        //base cases
        if(n == 1) return 1;
        if(n == 2) return 2;

        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 2;
        return solve_dp(dp, n);
        
    }

    int climbStairs(int n) {
        return tabulation(n);
    }
};