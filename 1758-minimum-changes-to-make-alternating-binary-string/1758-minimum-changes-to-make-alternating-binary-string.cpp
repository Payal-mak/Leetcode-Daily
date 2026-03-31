class Solution {
public:
    int minOperations(string s) {
        int minOp = 0;
        for(int i = 0; i < s.size(); i++){
            if(i % 2 == s[i] - '0'){
                minOp++;
            }
        }
        int mini = s.size() - minOp;
        return min(mini, minOp);
    }
};