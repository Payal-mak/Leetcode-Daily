typedef unordered_map<int, int> umii;

class FindSumPairs {
private:
    vector<int> nums1, nums2;
    umii freq;
    int max_e, min_e;

    void populate_map() { // O(n)
        for(int x : this->nums2) { freq[x]++; }
    }
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) { // O(mlgm + 4n) ~ O(n), k=4
        this->nums1 = nums1; // O(m)
        this->nums2 = nums2; // O(n)
        populate_map(); // O(n)
        sort(this->nums1.begin(), this->nums1.end()); // O(m log m)
        max_e = *max_element(nums2.begin(), nums2.end()); // O(n)
        min_e = *min_element(nums2.begin(), nums2.end()); // O(n)
    }
    
    void add(int index, int val) { // O(1)
        freq[nums2[index]]--;
        nums2[index] += val; // O(1)
        freq[nums2[index]]++;
        max_e = max(max_e, nums2[index]);
    }
    
    int count(int tot) { // O(m)
        int count = 0;
        int start = lower_bound(nums1.begin(), nums1.end(), tot - max_e) - nums1.begin(); // O(lg m)
        int end = upper_bound(nums1.begin(), nums1.end(), tot - min_e)  - nums1.begin(); // O(lg m)
        for(int i = start; i < end; i++) { // O(m)
            count += freq[tot - nums1[i]];
        }
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */