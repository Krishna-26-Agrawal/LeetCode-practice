class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(1024, 0));
        dp[0][grid[0][0]] = 1;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    continue;
                }

                vector<int> temp(1024, 0);
                int val = grid[i][j];

                for(int k = 0; k < 1024; k++){
                    if((i > 0 && dp[j][k]) ||
                       (j > 0 && dp[j - 1][k])){
                        temp[k ^ val] = 1;
                    }
                }

                dp[j] = temp;
            }
        }

        for(int k = 0; k < 1024; k++){
            if(dp[n - 1][k]){
                return k;
            }
        }

        return 0;
    }
};