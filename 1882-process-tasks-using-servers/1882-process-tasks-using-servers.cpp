class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int nServers = servers.size();
        int nTasks = tasks.size();
        vector<int> ans(nTasks);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq1;
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq2;

        for(int i = 0; i < nServers; i++){
            pq1.push({servers[i], i});
        }

        long long t = 0;
        for(int i = 0; i < nTasks; i++){
            t = max(t, (long long)i);

            if(pq1.empty()){
                t = get<0>(pq2.top());
            }

            while(!pq2.empty() && get<0>(pq2.top()) <= t){
                auto p = pq2.top();
                pq2.pop();
                pq1.push({get<1>(p), get<2>(p)});
            }

            auto temp = pq1.top();
            pq1.pop();

            int wt = temp.first;
            int idx = temp.second;

            ans[i] = idx;
            pq2.push({t + tasks[i], wt, idx});
        }

        return ans;
    }
};