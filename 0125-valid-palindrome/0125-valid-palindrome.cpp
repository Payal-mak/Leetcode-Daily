class Solution {
public:
    bool isPalindrome(string s) {
        int sz = s.size()-1;
        string t = "";
        string original = "";
        for(int i = sz; i>=0; i--){
            if(isalnum(s[i])){
                t += tolower(s[i]);
            }
        }
        // for(int i = 0; i<t.size(); i++){
        //     cout << t[i];
        // }
        for(int i = 0; i<s.size(); i++){
            if(isalnum(s[i])){
                original += tolower(s[i]);
            }
        }
        
        return original == t;
    }
};