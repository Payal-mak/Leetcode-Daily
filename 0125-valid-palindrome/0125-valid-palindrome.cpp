class Solution {
public:
    bool isPalindrome(string s) {
        string res = "";
        for(int i = 0; i < s.size(); i++){
            if(isalnum(s[i])){
                res += tolower(s[i]);
            }
        }
        int i = 0;
        int j = res.size()-1;
        while(i < j){
            if(res[i] != res[j]){
                return false;
                break;
            }
            i++;
            j--;
        }
        return true;
    }
};