class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string, int> freq;
        for(string s : words){
            freq[s]++;
        }
        vector<pair<int, string>> v;
        for(auto &it : freq){
            v.push_back({it.second, it.first});
        }
        sort(v.begin(), v.end(), [](auto &a, auto &b){
            if(a.first != b.first){
                return a.first > b.first;
            }
            return b.second > a.second;
        });
        for(int i = 0; i<k; i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};