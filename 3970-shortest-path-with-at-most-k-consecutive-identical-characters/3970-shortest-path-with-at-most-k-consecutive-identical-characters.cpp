class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        if(n == 1){
            return 0;
        }

        if(k <= 0){
            return -1;
        }

        vector<vector<pair<int, int>>> adjList(n);
        for(const auto& e : edges){
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adjList[u].push_back({v, wt});
        }

        vector<vector<long long>> dist(n, vector<long long>(k + 1, INT_MAX));
        priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> pq;

        dist[0][1] = 0;
        pq.push({0LL, {0, 1}});

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            long long d = top.first;
            int u = top.second.first;
            int wt = top.second.second;

            if(d > dist[u][wt]){
                continue;
            }

            if(u == n - 1){
                return d;
            }

            for(const auto& edge : adjList[u]){
                int v = edge.first;
                int w = edge.second;

                int temp = (labels[v] == labels[u]) ? (wt + 1) : 1;

                if(temp <= k){
                    if(d + w < dist[v][temp]){
                        dist[v][temp] = d + w;
                        pq.push({d + w, {v, temp}});
                    }
                }
            }
        }

        return -1;
    }
};