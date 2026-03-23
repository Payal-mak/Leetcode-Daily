class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //brute force approach
        int n = nums.size();
        //we will store all non-zero elements in another vector
        vector<int> non_zero;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                non_zero.push_back(nums[i]);
            }
        }
        //now push all non zero elements to starting of nums vector
        int nz = non_zero.size();
        for(int i = 0; i < nz; i++){
            nums[i] = non_zero[i];
        }
        //then push 0 to remaining empty places of nums vector
        for(int i = nz; i < n; i++){
            nums[i] = 0;
        }
    }
};