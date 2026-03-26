class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //better approach
        //using hashmaps
        int n = nums.size();
        unordered_map<int, int> mpp;

        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
        }
        for(auto it : mpp){
            if(it.second > n/2){
                return it.first;
            }
        }
        return 0;
    }
};