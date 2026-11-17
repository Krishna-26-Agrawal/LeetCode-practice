class Solution {
    int solve(string &s, int l, int r, int d){
        int count = 0;
        int sz = (r - l + 1) / d;

        for(int i = 0; i < d; i++){
            for(int j = 0; j < (sz / 2); j++){
                int left = l + i + j * d;
                int right = l + i + (sz - j - 1) * d;
                if(s[left] != s[right]){
                    count++;
                }
            }
        }

        return count;
    }
public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        int INF = 1e9;
        vector<vector<int>> temp(n, vector<int>(n, INF));

        for(int i = 2; i <= n; i++){
            for(int j = 0; j <= n - i; j++){
                int p = i + j - 1;

                for(int d = 1; d < i; d++){
                    if((i % d) == 0){
                        temp[j][p] = min(temp[j][p], solve(s, j, p, d));
                    }
                }
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[0][0] = 0;
        for(int i = 1; i <= k; i++){
            for(int j = i; j <= n; j++){
                for(int p = i - 1; p < j; p++){
                    if(temp[p][j - 1] != INF){
                        dp[j][i] = min(dp[j][i], dp[p][i - 1] + temp[p][j - 1]);
                    }
                }
            }
        }

        return dp[n][k];
    }
};