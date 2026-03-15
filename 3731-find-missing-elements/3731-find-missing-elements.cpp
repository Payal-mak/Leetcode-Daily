class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> res;

        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());

        unordered_set<int> s(nums.begin(), nums.end());

        for(int i = minVal; i <= maxVal; i++){
            if(s.find(i) == s.end()){
                res.push_back(i);
            }
        }

        return res;
    }
};