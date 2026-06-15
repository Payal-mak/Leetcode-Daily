class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        //brute-force approach
        for(int i = 0; i < n; i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(!ans.empty() && end <= ans.back()[1]){
                //then that element is already lying in the interval
                continue;
            }
            for(int j = i+1; j < n; j++){
                //if the starting is lesser than ending of previous interval
                //then it is overlapping
                if(intervals[j][0] <= end){
                    end = max(end, intervals[j][1]);
                }
                else{
                    //if not overlapping
                    break;
                }
            }
            ans.push_back({start,end});
        }
        return ans;
    }
};