class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        //optimized approach
        for(int i = 0; i < n; i++){
            //if the start element of interval is not a part of previous interval
            if(ans.empty() || intervals[i][0] > ans.back()[1]){
                //then create a new interval
                ans.push_back(intervals[i]);
            }
            else{
                //if second element of interval lies in the previous interval
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};