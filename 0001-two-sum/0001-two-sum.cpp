class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mpp;
        //now we loop through array
        for(int i = 0; i <  nums.size(); i++){
            int first = nums[i];
            int last = target - first;
            if(mpp.find(last) != mpp.end()){
                return {mpp[last], i};
            }
            mpp[first] = i;
        }
        return {};
    }
};