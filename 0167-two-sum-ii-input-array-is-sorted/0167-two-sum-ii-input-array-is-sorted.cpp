class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //without using extra space
        //using two pointers approach
        //as the array is already sorted, then we can check for two pointers
        int l = 0;
        int r = numbers.size()-1;
        while(l < r){
            int sum = numbers[l] + numbers[r];
            if(sum == target){
                return {l+1, r+1};
            }
            else if(sum < target){
                l++;
            }
            else{
                r--;
            }
        }
        return{1,2};
    }
};