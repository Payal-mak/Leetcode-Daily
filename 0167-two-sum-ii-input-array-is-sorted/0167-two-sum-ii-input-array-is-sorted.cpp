class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mpp;
        for(int i = 0; i < numbers.size(); i++){
            int first = numbers[i];
            int last = target - first;
            if(mpp.find(last) != mpp.end()){
                return {mpp[last]+1, i+1};
            }
            mpp[first] = i;
        }
        return {1, 2};
    }
};