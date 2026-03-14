class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x1 = nums.size();
        //x1 = XOR of all numbers from 1 to N
        //x2 = XOR of all numbers present in nums
        for(int i = 0; i < nums.size(); i++){
            x1 ^= i ^ nums[i];
        }
        return x1;
    }
};