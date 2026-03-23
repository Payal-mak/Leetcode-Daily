class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //two pointer approach
        int i = 0;
        for(int j = 1; j < nums.size(); j++){
            //we check if arr[j] == arr[i]
            //if yes, then continue
            //if no, then do i++;
            if(nums[j] == nums[i]){
                continue;
            }
            nums[i+1] = nums[j];
            i++;
        }
        //now i have to return count and also array till i
        return i+1;
    }
};