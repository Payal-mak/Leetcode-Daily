class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd;
        int currentMax = 0;
        // 1. Calculate prefixGcd using the original order of nums
        for (int i = 0; i < n; i++) {
            currentMax = max(currentMax, nums[i]);
            prefixGcd.push_back(std::gcd(nums[i], currentMax));
        }
        // 2. Sort the final prefixGcd array
        sort(prefixGcd.begin(), prefixGcd.end());
        // 3. Pair up elements from outside-in
        long long totalSum = 0;
        int left = 0;
        int right = n - 1;
        while (left < right) {
            totalSum += std::gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }
        return totalSum;
    }
};