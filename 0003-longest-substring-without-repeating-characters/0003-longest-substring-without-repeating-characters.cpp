class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;   // stores character → last index
        int l = 0, maxlen = 0;
        for (int r = 0; r < s.size(); r++) {
            // if character already seen and is inside current window
            if (hash.count(s[r]) && hash[s[r]] >= l) {
                l = hash[s[r]] + 1;     // move left pointer
            }
            hash[s[r]] = r;            // store/update last seen index
            maxlen = max(maxlen, r - l + 1);
        }
        return maxlen;
    }
};
