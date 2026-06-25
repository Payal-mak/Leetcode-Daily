class Solution {
public:
    int rec(vector<int>& nums, int i){
        //base cases
        if(i == 0) return nums[0];
        if(i == 1) return max(nums[0], nums[1]);
        //rcf
        int rob = max(
            //rob the current house and add money and look for house i-2
            rec(nums, i-2) + nums[i],
            //skip the current house, and look at house i-1
            rec(nums, i-1)
        );
        return rob;
    }
    int memoiz(vector<int>& nums, vector<int>& memo, int i){
        memo[0] = nums[0];
        memo[1] = max(nums[1], nums[0]);
        if(memo[i] != -1){
            return memo[i];
        }
        int rob = max(
            memoiz(nums, memo, i-2) + nums[i],
            memoiz(nums, memo, i-1)
        );
        return memo[i] = rob;
    }
    int memoization(vector<int>& nums, int n){
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        vector<int> memo(n, -1);
        return memoiz(nums, memo, n-1);
    }
    int helper1(vector<int>& nums, vector<int>& dp, int i){
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        for(int i = 2; i < nums.size(); i++){
            int rob = max(
                dp[i-2] + nums[i],
                dp[i-1]
            );
            dp[i] = rob;
        }
        return dp[nums.size()-1];
    }
    int tabulation(vector<int>& nums, int n){
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        vector<int> dp(n+1);
        return helper1(nums, dp, n-1);
    }
    int helper2(vector<int>& nums, int i){
        int prev2 = nums[0];
        int prev = max(nums[0], nums[1]);

        for(int i = 2; i < nums.size(); i++){
            int curr = max(
                prev2 + nums[i],
                prev
            );
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int space_opt(vector<int>& nums, int n){
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        return helper2(nums, n-1);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return space_opt(nums, n);
    }
};