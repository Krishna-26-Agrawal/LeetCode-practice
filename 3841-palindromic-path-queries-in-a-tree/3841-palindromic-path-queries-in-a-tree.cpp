class Solution {
    int timer;
    vector<int> tin, tout, depth;
    vector<vector<int>> up;
    vector<vector<int>> adj;
    vector<int> bit;
    int N;

    void updatePoint(int idx, int delta){
        for(; idx <= N; idx += idx & -idx){
            bit[idx] ^= delta;
        }
    }

    void updateRange(int l, int r, int delta){
        updatePoint(l, delta);
        updatePoint(r + 1, delta);
    }

    int queryPoint(int idx){
        int res = 0;

        for(; idx > 0; idx -= idx & -idx){
            res ^= bit[idx];
        }

        return res;
    }

    void dfs(int u, int p, int d, int cur_mask, const string& s){
        tin[u] = ++timer;
        depth[u] = d;
        up[u][0] = p;

        for (int i = 1; i < 18; ++i) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }

        int node_bit = 1 << (s[u] - 'a');
        cur_mask ^= node_bit;

        updatePoint(tin[u], cur_mask);
        updatePoint(tin[u] + 1, cur_mask);

        for(int v : adj[u]){
            if(v != p) 
            {
                dfs(v, u, d + 1, cur_mask, s);
            }
        }

        tout[u] = timer;
    }

    int getLCA(int u, int v){
        if(depth[u] < depth[v])
            swap(u, v);

        for(int i = 17; i >= 0; i--){
            if(depth[u] - (1 << i) >= depth[v]){
                u = up[u][i];
            }
        }

        if(u == v)
            return u;

        for(int i = 17; i >= 0; i--){
            if(up[u][i] != up[v][i]){
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        N = n;
        adj.assign(n, vector<int>());

        for(const auto& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        up.assign(n, vector<int>(18, 0));
        bit.assign(n + 2, 0);
        timer = 0;

        dfs(0, 0, 0, 0, s);

        vector<int> char_mask(n);
        for(int i = 0; i < n; i++){
            char_mask[i] = 1 << (s[i] - 'a');
        }

        vector<bool> ans;
        for(const string& q : queries){
            stringstream ss(q);
            string type;
            ss >> type;
            
            if(type == "update"){
                int u;
                char c;
                ss >> u >> c;

                int new_mask = 1 << (c - 'a');
                int delta = char_mask[u] ^ new_mask;

                if(delta != 0){
                    char_mask[u] = new_mask;
                    updateRange(tin[u], tout[u], delta);
                }
            }
            else{
                int u, v;
                ss >> u >> v;

                int lca = getLCA(u, v);
                int dist_u = queryPoint(tin[u]);
                int dist_v = queryPoint(tin[v]);
                int path_xor = dist_u ^ dist_v ^ char_mask[lca];

                ans.push_back((path_xor & (path_xor - 1)) == 0);
            }
        }

        return ans;
    }
};