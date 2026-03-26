class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //optimal approach
        //using XOR
        //xor of same numbers is 0
        //0 ^ (number) = number itself
        int xorr = 0;
        for(int i = 0; i < nums.size(); i++){
            xorr ^= nums[i];
        }
        return xorr;
    }
};