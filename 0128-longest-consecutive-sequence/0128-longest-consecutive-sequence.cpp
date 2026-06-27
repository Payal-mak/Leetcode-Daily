class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //better solution
        if(nums.empty()) return 0;
        //we will initialize three variables
        sort(nums.begin(), nums.end());
        int cntCurr = 0;
        int lastSmaller = INT_MIN;
        int longest = 1;
        for(int i = 0; i < nums.size(); i++){
            int x = nums[i];
            if(nums[i] - 1 == lastSmaller){
                cntCurr++;
                lastSmaller = nums[i];
            }
            else if(lastSmaller != nums[i]){
                cntCurr = 1;
                lastSmaller = nums[i];
            }
            longest = max(longest, cntCurr);
        }
        return longest;
    }
};