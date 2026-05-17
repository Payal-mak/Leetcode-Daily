#include <sstream>
class Solution {
public:
    string reverseWords(string s) {
        //ex: s = "the sky is blue"
        //"eulb si yks eht"
        reverse(s.begin(), s.end());
        string ans = "";

        //now we will again reverse individual word
        for(int i = 0; i < s.size();i++){
            string word = "";
            while(i < s.size() && s[i] != ' '){
                word += s[i];
                i++;
            }
            reverse(word.begin(), word.end());
            if(word.length() > 0){
                ans += " " + word;
            }
        }
        return ans.substr(1);
    }
};