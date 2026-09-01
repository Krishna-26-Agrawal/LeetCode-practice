struct State{
    int x;
    int y;
    int energy;
    int mask;
};

class Solution {
public:
    int minMoves(vector<string>& classroom, int max_energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int start_x = -1, start_y = -1;
        int cnt = 0;
        vector<vector<int>> litter_id(m, vector<int>(n, -1));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (classroom[i][j] == 'S'){
                    start_x = i;
                    start_y = j;
                }
                else if(classroom[i][j] == 'L'){
                    litter_id[i][j] = cnt++;
                }
            }
        }
        
        if(cnt == 0)
            return 0;
        
        int initial_mask = (1 << cnt) - 1; 
        
        queue<State> q;
        q.push({start_x, start_y, max_energy, initial_mask});

        vector<vector<vector<vector<bool>>>> vis(
            m, vector<vector<vector<bool>>>(
                n, vector<vector<bool>>(
                    max_energy + 1, vector<bool>(1 << cnt, false)
                )
            )
        );
        
        vis[start_x][start_y][max_energy][initial_mask] = true;
        int moves = 0;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                State curr = q.front();
                q.pop();
                
                if(curr.energy == 0) 
                    continue;
                
                for(auto& dir : dirs){
                    int nx = curr.x + dir[0];
                    int ny = curr.y + dir[1];

                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && classroom[nx][ny] != 'X'){
                        int nxt_energy = curr.energy - 1;
                        if(classroom[nx][ny] == 'R'){
                            nxt_energy = max_energy; 
                        }
                        
                        int nxt_mask = curr.mask;
                        if(classroom[nx][ny] == 'L' && (curr.mask & (1 << litter_id[nx][ny]))){
                            nxt_mask ^= (1 << litter_id[nx][ny]); 
                        }

                        if(nxt_mask == 0) 
                            return moves + 1;

                        if(!vis[nx][ny][nxt_energy][nxt_mask]){
                            vis[nx][ny][nxt_energy][nxt_mask] = true;
                            q.push({nx, ny, nxt_energy, nxt_mask});
                        }
                    }
                }
            }

            moves++; 
        }
        
        return -1; 
    }
};