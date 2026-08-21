class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        vector<pair<long long, int>> valid;

        for(int i = 1; i < (1 << n); i++){
            long long curr = 1;

            for(int j = 0; j < n; j++){
                if((i >> j) & 1){
                    curr = lcm(curr, (long long)coins[j]);
                }
            }

            int set = __builtin_popcount(i);
            int sign = (set % 2 == 1) ? 1 : -1;

            valid.push_back({curr, sign});
        }

        long long s = 1;
        long long mini = LLONG_MAX;
        for(int i : coins){
            mini = min(mini, (long long)i);
        }

        long long e = mini * k;
        long long ans = e;

        while(s <= e){
            long long mid = s + (e - s) / 2;
            long long count = 0;

            for(auto p : valid){
                count += (p.second * (mid / p.first));
            }

            if(count >= k){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }

        return ans;
    }
};