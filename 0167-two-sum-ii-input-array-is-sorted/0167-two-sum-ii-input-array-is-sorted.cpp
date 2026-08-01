class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> mpp;
        for(int i = 0; i < numbers.size(); i++){
            int first = numbers[i];
            int second = target - first;
            if(mpp.find(second) != mpp.end()){
                return {mpp[second]+1,i+1};
            }
            mpp[first] = i;
        }
        return {1,2};
    }
};