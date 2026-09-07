class Solution {
public:
    int distinctSubseqII(string s) {
        long long MOD = 1e9 + 7;
        vector<long long> dp(26, 0);
        long long total = 0;
        
        for (char c : s) {
            int i = c - 'a';
            long long temp = (total + 1) % MOD;
            
            total = (total - dp[i] + temp + MOD) % MOD;
            dp[i] = temp;
        }
        
        return total;        
    }
};