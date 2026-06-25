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
    int rob(vector<int>& nums) {
        int n = nums.size();
        return memoization(nums, n);
    }
};