class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> count(k, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        set<int> st;
        for(int i = 0; i < k; i++){
            st.insert(i);
        }

        int n = arrival.size();
        for(int i = 0; i < n; i++){
            long long t = arrival[i];
            long long d = load[i];
            
            while(!pq.empty() && pq.top().first <= t){
                st.insert(pq.top().second);
                pq.pop();
            }

            if(st.empty()){
                continue;
            }

            int target = i % k;
            auto it = st.lower_bound(target);

            if(it == st.end()){
                it = st.begin();
            }

            int temp = *it;

            count[temp]++;
            st.erase(it);
            pq.push({t + d, temp});
        }

        int maxi = INT_MIN;
        for(int i : count){
            maxi = max(maxi, i);
        }

        vector<int> result;
        for(int i = 0; i < k; i++){
            if(count[i] == maxi){
                result.push_back(i);
            }
        }

        return result;   
    }
};