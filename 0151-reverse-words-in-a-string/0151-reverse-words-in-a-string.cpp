class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        //first reverse the whole string
        reverse(s.begin(), s.end());
        //now reverse the individual words
        for(int i = 0; i<n; i++){
            string word = "";
            while(i < n and s[i] != ' '){
                word += s[i];
                i++;
            }
            reverse(word.begin(), word.end());
            if(word.length() > 0){
                ans += " "+word;
            }
        }
        return ans.substr(1);
    }
};