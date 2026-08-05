class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int, list<int>> adjList;
        for(auto i : invocations){
            int u = i[0];
            int v = i[1];

            adjList[u].push_back(v);
        }

        vector<int> sus(n, 0);
        sus[k] = 1;

        queue<int> q;
        q.push(k);

        while(!q.empty()){
            int frontEl = q.front();
            q.pop();

            for(int neighbour : adjList[frontEl]){
                if(!sus[neighbour]){
                    sus[neighbour] = 1;
                    q.push(neighbour);
                }
            }
        }

        bool remove = true;
        for(auto i : invocations){
            int u = i[0];
            int v = i[1];

            if(!sus[u] && sus[v]){
                remove = false;
                break;
            }
        }

        vector<int> ans;
        if(remove){
            for(int i = 0; i < n; i++){
                if(!sus[i]){
                    ans.push_back(i);
                }
            }
        }
        else{
            for(int i = 0; i < n; i++){
                ans.push_back(i);
            }
        }

        return ans;
    }
};