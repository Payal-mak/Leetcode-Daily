class Solution {
public:
    int lengthOfLastWord(string s) {
        int j = 0;
        bool counting = false;
        for(int i = s.size()-1; i>=0; i--){
            if(s[i] != ' '){
                counting = true;
                j++;
            }
            else if(counting){
                break;
            }
        }
        return j;
    }
};