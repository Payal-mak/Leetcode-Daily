class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //brute force approach
        set<int> st;
        for(int i = 0; i < nums.size(); i++){
            st.insert(nums[i]);
        }
        //set will have only the unique elements stored. but we have to return nums where starting k elements are unique and remaining elements are kept blanks
        int i = 0;
        for (auto it : st){
            nums[i] = it; //copy back to the nums
            i++;
        }
        return st.size();
    }
};