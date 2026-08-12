class Solution {
public:
    bool isPossible(vector<int> &bloomDay, int m, int adj, int day) {
        int cnt = 0;
        int bouq = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                cnt++;
                if (cnt == adj) {
                    bouq++;
                    cnt = 0;
                }
            }
            else {
                cnt = 0;
            }
        }
        return bouq >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        // base case
        if ((long long)m * k > n) return -1;
        int minDay = *min_element(bloomDay.begin(), bloomDay.end());
        int maxDay = *max_element(bloomDay.begin(), bloomDay.end());
        while (minDay <= maxDay) {
            int mid = minDay + (maxDay - minDay) / 2;
            if (isPossible(bloomDay, m, k, mid)) {
                maxDay = mid - 1;
            }
            else {
                minDay = mid + 1;
            }
        }
        return minDay;
    }
};