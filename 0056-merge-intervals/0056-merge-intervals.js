/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function(intervals) {
    intervals.sort((a,b) => a[0]-b[0]);
    const ans =[];
    ans.push(intervals[0]);

    for(let i = 1; i<intervals.length; i++){
        if(intervals[i][1] <= ans[ans.length-1][1]){
            continue;
        }
        if(intervals[i][0] <= ans[ans.length-1][1]){
            ans[ans.length-1][1] = intervals[i][1];
        }
        else{
            ans.push(intervals[i]);
        }
    }
    return ans;
};