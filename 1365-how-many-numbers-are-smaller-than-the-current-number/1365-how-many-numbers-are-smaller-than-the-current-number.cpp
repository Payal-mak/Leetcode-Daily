class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count(101, 0);

        // Step 1: Count frequency
        for(int num : nums){
            count[num]++;
        }

        // Step 2: Prefix sum
        for(int i = 1; i <= 100; i++){
            count[i] += count[i - 1];
        }

        // Step 3: Build result
        vector<int> result;

        for(int num : nums){
            if(num == 0)
                result.push_back(0);
            else
                result.push_back(count[num - 1]);
        }

        return result;
    }
};