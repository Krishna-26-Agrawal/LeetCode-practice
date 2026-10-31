class Solution {
public:
    int MOD = 1e9 + 7;
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<pair<int, int>>>> dest(
            m, vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(2, {-1, -1}))
        );

        auto getNextCell = [&](auto& self, int r, int c, int dir) -> pair<int, int> {
            if(r >= m || c >= n){
                return {-2, -2};
            }

            if(grid[r][c] == 0 || (r == m - 1 && c == n - 1)){
                return {r, c};
            }

            if(dest[r][c][dir].first != -1){
                return dest[r][c][dir];
            }

            pair<int, int> result;

            if(dir == 0){
                result = self(self, r + 1, c, 1);
            }
            else{
                result = self(self, r, c + 1, 0);
            }

            return dest[r][c][dir] = result;
        };

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m - 1][n - 1] = 1;

        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(grid[i][j] == 1 || (i == m - 1 && j == n - 1)){
                    continue;
                }

                long long count = 0;

                auto [x1, y1] = getNextCell(getNextCell, i, j + 1, 0);
                if(x1 >= 0 && y1 >= 0){
                    count = (count + dp[x1][y1]) % MOD;
                }

                auto [x2, y2] = getNextCell(getNextCell, i + 1, j, 1);
                if(x2 >= 0 && y2 >= 0){
                    count = (count + dp[x2][y2]) % MOD;
                }

                dp[i][j] = count;
            }
        }

        return dp[0][0];
    }
};