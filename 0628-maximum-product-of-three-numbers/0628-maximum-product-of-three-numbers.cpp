class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // for(int i = 0; i<n; i++){
        //     cout << nums[i] << " ";
        // }
        int product1, product2;
        product1 = nums[n-1]*nums[n-2]*nums[n-3];
        product2 = nums[0]*nums[1]*nums[n-1];
        return max(product1, product2);
    }
};