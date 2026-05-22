class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;

        for(int i = 0; i < arr.size(); i++){
            freq[arr[i]]++;
        }

        unordered_set<int> seen;

        for(const auto& pair : freq){
            int unique = pair.second;

            if(seen.count(unique)){
                return false;
            }
            seen.insert(unique);
        }

        return true;
    }
};