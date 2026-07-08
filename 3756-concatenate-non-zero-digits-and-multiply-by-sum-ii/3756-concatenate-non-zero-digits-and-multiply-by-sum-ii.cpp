class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size(), MOD = 1e9 + 7, m = queries.size();
        vector<long long> prefixSum(n + 1, 0);
        vector<long long> powerValue(n + 1, 1);
        vector<long  long> prefixValue(n + 1, 0);
        vector<int> count(n + 1, 0);

        for(int i = 1; i <= n; i++){
            powerValue[i] = (powerValue[i - 1] * 10) % MOD;

            int digit = s[i - 1] - '0';
            prefixSum[i] = prefixSum[i - 1] + digit;

            count[i] = (digit != 0) ? (count[i - 1] + 1) : count[i - 1];
            prefixValue[i] = (digit != 0) ? ((prefixValue[i - 1] * 10 + digit) % MOD) : prefixValue[i - 1];
        }

        vector<int> ans(m);
        int k = 0;

        for(auto q : queries){
            int l = q[0] + 1, r = q[1] + 1;

            long long f = prefixSum[r] - prefixSum[l - 1];

            int x = count[r] - count[l - 1];
            long long y = (prefixValue[l - 1] * powerValue[x]) % MOD;

            long long st = (prefixValue[r] - y) % MOD;

            if(st < 0){
                st += MOD;
            }

            ans[k++] = (f * st) % MOD;
        }

        return ans;
    }
};