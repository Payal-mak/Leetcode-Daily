#include<bits/stdc++.h>
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int culprits = 0;
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] < nums[i - 1])
            {
                ++culprits;
            }
        }
        if (nums[0] < nums[n - 1])
        {
            ++culprits;
        }
        return culprits <= 1;        
    }
};