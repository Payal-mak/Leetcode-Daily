class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int op = 0;
        unordered_map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++){

            int first = nums[i];
            int second = k - first;

            if(mpp.find(second) != mpp.end() && mpp[second] > 0){
                op++;
                mpp[second]--;
            }
            else{
                mpp[first]++;
            }
        }
        return op;
    }
};