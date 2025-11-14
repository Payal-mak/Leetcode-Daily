class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastIndex;

        for(int i = 0; i < nums.size(); i++){
            if(lastIndex.count(nums[i])) {
                // check distance
                if(i - lastIndex[nums[i]] <= k)
                    return true;
            }
            // update last seen index
            lastIndex[nums[i]] = i;
        }
        return false;
    }
};
