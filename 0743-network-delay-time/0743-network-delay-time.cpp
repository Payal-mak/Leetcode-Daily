class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Adjacency list: {neighbor, weight}
        vector<vector<pair<int, int>>> li(n + 1);
        for (auto &edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            li[u].push_back({v, w});
        }
        // Distance array
        vector<int> dist(n + 1, INT_MAX);

        // Min-heap: {distance, node}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            // Ignore outdated entries
            if (d > dist[node])
                continue;

            for (auto &[next, wt] : li[node]) {
                if (dist[node] + wt < dist[next]) {
                    dist[next] = dist[node] + wt;
                    pq.push({dist[next], next});
                }
            }
        }

        int ans = 0;

        // Ignore index 0 because nodes are 1-indexed
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};