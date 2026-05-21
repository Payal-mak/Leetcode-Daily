class Solution {
public:
    int compress(vector<char>& chars) {
        //idx pointer for tracking in-place replaced characters
        int idx = 0;
        for(int i = 0; i< chars.size(); i++){
            int cnt = 0;
            char ch = chars[i];
            //calculate count for individual continuouscharacters
            while(i < chars.size() && chars[i] == ch){
                cnt++;
                i++;
            }
            //if count = 1, just replace with character
            if(cnt == 1){
                chars[idx++] = ch;
            }
            else{
                chars[idx++] = ch;
                //convert integer to string, for example, ["a","2"]
                string str = to_string(cnt);
                //if count is a 2-digit number, then ["a","2","0"]
                for(char digit : str){
                    chars[idx++] = digit;
                }
            }
            //we need to decrement i, for counting different character
            i--;
        }
        return idx;
    }
};