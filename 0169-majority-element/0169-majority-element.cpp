class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //brute-force approach
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n/2]; //because majority element occurs more than n/2 times, and when the array is sorted, it will occupy the middle position.
    }
};