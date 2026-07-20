class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, list<pair<int, int>>> adjList;
        for(auto i : times){
            int u = i[0];
            int v = i[1];
            int wt = i[2];

            adjList[u].push_back({v, wt});
        }

        queue<pair<int, int>> q;
        q.push({k, 0});
        
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            int curr = p.first;
            int dis = p.second;

            if(dis == INT_MAX){
                return -1;
            }

            for(auto neighbour : adjList[curr]){
                int el = neighbour.first;
                int wt = neighbour.second;

                if(dis + wt < dist[el]){
                    dist[el] = dis + wt;

                    q.push({el, dis + wt});
                }
            }
        }
        
        int maxEl = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX){
                return -1;
            }

            maxEl = max(maxEl, dist[i]);
        }

        return maxEl;
    }
};