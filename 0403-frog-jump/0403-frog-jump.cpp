class Solution {
public:
    //stores the position of each stone, for O(1) lookup.
    unordered_map<int, int> pos;
    //memoization table, dp[currStone][prevJump]
    //currStone = index of current stone
    //prevJump = size of last jump taken
    //this stores whether the frog can reach to last stone from current stone "currStone" with previous jump "prevJump"
    vector<vector<int>> dp;

    bool solve(vector<int> &stones, int currStone, int prevJump){
        //if frog has reached the last stone, then return true
        if(currStone == stones.size()-1){
            return true;
        }
        //if this state is already computed, then simply return the stored result
        if(dp[currStone][prevJump] != -1){
            return dp[currStone][prevJump];
        }
        for(int nextJump = prevJump - 1; nextJump <= prevJump+1; nextJump++){
            //next jump cannot be 0 or negative
            if(nextJump <= 0){
                continue;
            }
            int nextStone = stones[currStone]+ nextJump;

            //Check whether a stone exists at nextStone.
            //if found, returns 1, else 0
            if(pos.count(nextStone)){
                if(solve(stones, pos[nextStone], nextJump)){
                    //if that path succeeds, stores true in dp, return true
                    return dp[currStone][prevJump] = true;
                }
            }
        }
        return dp[currStone][prevJump] = false;
    } 

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        for(int i = 0; i < n; i++){
            pos[stones[i]] = i;
        }
        dp.resize(n, vector<int>(n+1, -1));

        return solve(stones, 0, 0);
    }
};