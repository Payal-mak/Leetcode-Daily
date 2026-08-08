class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string, int> freq;
        for(string s : words){
            freq[s]++;
        }
        vector<pair<int, string>> v;
        //sort by most frequent elements
        for(auto &it : freq){
            v.push_back({-it.second, it.first});
        }
        sort(v.begin(), v.end());
        // for(auto p : v){
        //     cout << p.second << " ";
        // }
        for(int i = 0; i<k; i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};