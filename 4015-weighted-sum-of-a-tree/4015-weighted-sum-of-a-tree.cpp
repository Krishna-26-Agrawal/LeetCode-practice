class Solution {
public:
    void dfs(int node, int d, unordered_map<int, list<int>> &adjList, int &h){
        h = max(h, d);
        
        for(int neighbour : adjList[node]){
            dfs(neighbour, d + 1, adjList, h);
        }
    }
    
    long long weightedSum(vector<int>& parent, vector<int>& nums) {        
        int n = parent.size();
        unordered_map<int, list<int>> adjList;
        
        for(int i = 1; i < n; i++){
            int u = parent[i];
            int v = i;
            
            adjList[u].push_back(v);
        }
        
        int h = 0;
        dfs(0, 1, adjList, h); 

        queue<pair<int, int>> q;
        long long total = (long long)h * nums[0]; 
        
        q.push({0, 1});

        while(!q.empty()){
            auto frontEl = q.front();
            q.pop();

            int el = frontEl.first;
            int d = frontEl.second;

            for(int neighbour : adjList[el]){
                int temp = d + 1;
                q.push({neighbour, temp});
                total += ((long long)nums[neighbour] * (h - temp + 1));
            }
        }

        return total;
    }
};