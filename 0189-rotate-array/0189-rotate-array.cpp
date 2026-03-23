class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //optimal approach
        //ex: nums[] = [1,2,3,4,5], k = 2
        int n = nums.size();
        k = k % n;
        //first reverse the whole array
        //nums[] = [5,4,3,2,1]
        reverse(nums.begin(), nums.end());
        //reverse the first k elements
        //nums[4,5,3,2,1]
        reverse(nums.begin(), nums.begin()+k);
        //reverse the remaining n-k elements
        //nums[] = [4,5,1,2,3]
        reverse(nums.begin()+k, nums.end());
    }
};