class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x1 = 0, x2 = 0;
        //x1 = XOR of all numbers from 1 to N
        //x2 = XOR of all numbers present in nums
        for(int i = 1; i <= nums.size(); i++){
            x1 ^= i;
        }
        for(int num : nums){
            x2 ^= num;
        }
        return x1 ^ x2;
    }
};