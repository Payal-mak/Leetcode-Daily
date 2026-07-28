class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int> mpp;
        for(int i = 0; i<s.size(); i++){
            mpp[s[i]]++;
        }
        int count = mpp.begin()->second;
        for(auto &it : mpp){
            // cout << second << " ";
            if(count != it.second){
                return false;
            }
        }
        return true;
    }
};