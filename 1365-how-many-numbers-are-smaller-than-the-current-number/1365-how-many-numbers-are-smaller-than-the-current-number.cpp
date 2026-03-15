class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        unordered_map<int,int> mpp;

        for(int i = 0; i < sorted.size(); i++){
            if(mpp.find(sorted[i]) == mpp.end()){
                mpp[sorted[i]] = i;
            }
        }

        vector<int> res;

        for(int i = 0; i < nums.size(); i++){
            res.push_back(mpp[nums[i]]);
        }

        return res;
    }
};