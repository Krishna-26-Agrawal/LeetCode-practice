class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dirRow = {-1, 1, 0, 0};
        vector<int> dirCol = {0, 0, -1, 1};

        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] > 0){
                    long long sum = 0;
                    queue<pair<int, int>> q;

                    q.push({i, j});
                    sum += grid[i][j];
                    grid[i][j] = 0;

                    while(!q.empty()){
                        auto p = q.front();
                        q.pop();
                        int r = p.first;
                        int c = p.second;

                        for(int k = 0; k < 4; k++){
                            int x = r + dirRow[k];
                            int y = c + dirCol[k];

                            if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] > 0){
                                sum += grid[x][y];
                                grid[x][y] = 0;
                                q.push({x, y});
                            }
                        }
                    }

                    if(sum % k == 0){
                        count++;
                    }
                }
            }
        }

        return count;
    }
};