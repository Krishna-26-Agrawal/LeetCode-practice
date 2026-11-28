class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> freq(n + 1, 0);
        long long minPrice = 2e9;

        for(int i = 0; i < n; i++){
            freq[items[i][0]]++;
            minPrice = min(minPrice, (long long)items[i][1]);
        }

        vector<int> count(n + 1, 0);

        for(int i = 1; i <= n; i++){
            if(freq[i] == 0){
                continue;
            }

            for(int j = i; j <= n; j += i){
                count[i] += freq[j];
            }
        }

        vector<pair<long long, long long>> bun;
        bun.reserve(n);

        for(int i = 0; i < n; i++){
            int f = items[i][0];
            long long p = items[i][1];
            long long temp = count[f] - 1;

            if(temp > 0 && p < 2 * minPrice){
                bun.push_back({p, temp});
            }
        }

        sort(bun.begin(), bun.end());

        long long rem = budget;
        long long total = 0;
        long long lastPrice = -1;

        for(auto i: bun){
            long long p = i.first;
            long long cnt = i.second;
            if(rem < p)
                break;
            
            long long temp = min(cnt, rem / p);
            total += temp * 2;
            rem -= temp * p;

            if(temp > 0){
                lastPrice = p;
            }
        }

        long long ans = total + (rem / minPrice);

        if(lastPrice != -1){
            ans = max(ans, (total - 2) + ((rem + lastPrice) / minPrice));
        }

        return ans;  
    }
};