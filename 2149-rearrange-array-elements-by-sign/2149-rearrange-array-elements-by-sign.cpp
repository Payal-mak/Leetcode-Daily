class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int posIndex = 0;
        int negIndex = 1;
        vector<int> sorted(nums.size());
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                sorted[posIndex] = nums[i];
                posIndex+=2;
            }
            if(nums[i] < 0){
                sorted[negIndex] = nums[i];
                negIndex+=2;
            }
        }
        return sorted;
    }
};