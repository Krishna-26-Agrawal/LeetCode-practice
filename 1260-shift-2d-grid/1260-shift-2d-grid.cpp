class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        k = k % (m * n);

        if(k == 0){
            return grid;
        }

        vector<vector<int>> result(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int temp = (i * n + j + k) % (m * n);

                int x = temp / n;
                int y = temp % n;

                result[x][y] = grid[i][j];
            }
        }

        return result;
    }
};