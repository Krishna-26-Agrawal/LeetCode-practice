class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, list<pair<int, int>>> adjList;
        for(auto i : flights){
            int u = i[0];
            int v = i[1];
            int wt = i[2];

            adjList[u].push_back({v, wt});
        }

        queue<pair<int, pair<int, int>>> q;
        q.push({src, {0, 0}});

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            int node = p.first;
            int cost = p.second.first;
            int stops = p.second.second;

            if(stops > k){
                continue;
            }

            for(auto neighbour : adjList[node]){
                int el = neighbour.first;
                int wt = neighbour.second;

                if(cost + wt < dist[el] && stops <= k){
                    dist[el] = cost + wt;
                    q.push({el, {cost + wt, stops + 1}});
                }
            }
        }

        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};