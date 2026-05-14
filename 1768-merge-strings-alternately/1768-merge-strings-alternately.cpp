class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        // two pointers
        int word1_size = word1.size();
        int word2_size = word2.size();
        int max_size = max(word1_size, word2_size);

        string ans = "";

        for(int i = 0; i < max_size; i++) {

            if(i < word1_size) {
                ans.push_back(word1[i]);
            }

            if(i < word2_size) {
                ans.push_back(word2[i]);
            }
        }

        return ans;
    }
};