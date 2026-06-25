class Solution {
public:
    int helper2(vector<int>& nums, int start, int last){
        if(start == last) return nums[start];
        int prev2 = nums[start];
        int prev = max(nums[start+1], nums[start]);

        for(int i = start+2; i <= last; i++){
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
        int case1 = helper2(nums, 0, n-2); //exclude the last house
        int case2 = helper2(nums, 1, n-1); //exclude the first house
        return max(case1, case2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return space_opt(nums, n);
    }
};