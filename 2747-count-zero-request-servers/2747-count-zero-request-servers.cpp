class Solution {
public:
    static bool comp(const vector<int> &a, const vector<int> &b){
        return a[1] < b[1];
    }

    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();
        vector<int> ans(m);

        sort(logs.begin(), logs.end(), comp);

        vector<pair<int, int>> v(m);
        for(int i = 0; i < m; i++){
            v[i] = {queries[i], i};
        }
        sort(v.begin(), v.end());

        vector<int> count(n + 1, 0);
        int active = 0;
        int l = 0;
        int r = 0;
        int sz = logs.size();

        for(auto p : v){
            int time = p.first;
            int idx = p.second;
            int start = time - x;
            int end = time;

            while(r < sz && logs[r][1] <= end){
                int id = logs[r][0];

                if(count[id] == 0){
                    active++;
                }

                count[id]++;
                r++;
            }

            while(l < sz && logs[l][1] < start){
                int id = logs[l][0];

                count[id]--;
                if (count[id] == 0) {
                    active--;
                }

                l++;
            }

            ans[idx] = n - active;
        }

        return ans;
    }
};