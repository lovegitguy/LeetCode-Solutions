class Solution {
public:
    long long minCost(int n, string colors, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        auto narviletho = make_tuple(n, edges, colors);

        vector<int> parent(n, -1);
        vector<int> order;

        order.push_back(0);
        parent[0] = 0;

        for(int i = 0; i < order.size(); i++) {
            int u = order[i];

            for(int v : adj[u]) {
                if(v == parent[u]) continue;

                parent[v] = u;
                order.push_back(v);
            }
        }

        vector<long long> sub(n, 1);

        for(int i = n - 1; i > 0; i--) {
            int u = order[i];
            sub[parent[u]] += sub[u];
        }

        long long total = 0;

        for(int i = 0; i < n; i++) {
            if(colors[i] == 'R') {
                total += sub[i];
            }
        }

        vector<long long> dp(n, 0);
        long long best = 0;

        for(int i = n - 1; i >= 0; i--) {
            int u = order[i];

            long long gain = (colors[u] == 'R' ? sub[u] : -sub[u]);

            for(int v : adj[u]) {
                if(parent[v] == u) {
                    gain += max(0LL, dp[v]);
                }
            }

            dp[u] = gain;
            best = max(best, dp[u]);
        }

        return total - best;
    }
};