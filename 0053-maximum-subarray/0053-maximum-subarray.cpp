class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //optimal approach
        //kadane's algorithm
        int n = nums.size();
        long long maxi = LLONG_MIN;
        long long curr_sum = 0;
        if(n == 1) return nums[0];
        for(int i = 0; i < n; i++){
            //calculate the sum
            curr_sum += nums[i];
            maxi = max(maxi, curr_sum);
            //if the sum becomes negative, then reset sum to 0
            if(curr_sum < 0){
                curr_sum = 0;
            }
        }
        return maxi;
    }
};