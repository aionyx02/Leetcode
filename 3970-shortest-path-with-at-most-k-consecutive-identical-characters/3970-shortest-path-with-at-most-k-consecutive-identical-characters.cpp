class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }

        priority_queue<tuple<long long, int, int>,
                            vector<tuple<long long, int, int>>,
                            greater<tuple<long long, int, int>>> pq;

        const long long INF = 1e18;

        vector<vector<long long>> dist(n, vector<long long>(k + 1, INF));


        int start_cnt = 1;
        dist[0][start_cnt] = 0;
        pq.push({0, 0, start_cnt});

        while(!pq.empty()) {
            auto [d, u, cnt] = pq.top();
            pq.pop();

            if (u == n - 1) {
                return d;
            }

            if (d > dist[u][cnt]) {
                continue;
            }

            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int w = neighbor.second;

                int next_cnt = 1;
                if (labels[v] == labels[u]) {
                    next_cnt = cnt + 1;
                }

                if (next_cnt <= k) {
                    if (dist[u][cnt] + w < dist[v][next_cnt]) {
                        dist[v][next_cnt] = dist[u][cnt] + w;
                        pq.push({dist[v][next_cnt], v, next_cnt});
                    }
                }
            }
        }

        return -1;
    }
};