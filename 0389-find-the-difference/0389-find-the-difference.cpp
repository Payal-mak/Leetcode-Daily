class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum_T = 0;
        int sum_S = 0;

        for(int i = 0; i<t.size(); i++){
            sum_T += t[i];
        }
        for(int i = 0; i<s.size(); i++){
            sum_S += s[i];
        }
        return char(sum_T - sum_S);
    }
};