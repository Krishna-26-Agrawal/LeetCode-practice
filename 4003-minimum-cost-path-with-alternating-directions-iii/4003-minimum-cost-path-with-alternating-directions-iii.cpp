class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;

        vector<vector<vector<long long>>> dist(m, vector<vector<long long>>(n, vector<long long>(2, LLONG_MAX)));

        dist[0][0][1] = 1;
        pq.push({1LL, 0, 0, 1});

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            long long cost = curr[0];
            int x = curr[1];
            int y = curr[2];
            int z = curr[3];

            if(x == m - 1 && y == n - 1){
                return cost;
            }

            if(cost > dist[x][y][z]){
                continue;
            }

            int next = 1 - z;

            long long wait = penalty[x][y];
            if(dist[x][y][next] > cost + wait){
                dist[x][y][next] = cost + wait;
                pq.push({cost + wait, x, y, next});
            }

            if(y + 1 < n){
                long long temp = (x + 1LL) * (y + 2LL);

                if(z != 1){
                    temp += penalty[x][y];
                }

                if(dist[x][y + 1][next] > cost + temp){
                    dist[x][y + 1][next] = cost + temp;
                    pq.push({cost + temp, x, y + 1, next});
                }
            }

            if(x + 1 < m){
                long long temp = (x + 2LL) * (y + 1LL);

                if(z != 1){
                    temp += penalty[x][y];
                }

                if(dist[x + 1][y][next] > cost + temp){
                    dist[x + 1][y][next] = cost + temp;
                    pq.push({cost + temp, x + 1, y, next});
                }
            }

            if(y - 1 >= 0){
                long long temp = (x + 1LL) * (y * 1LL);

                if(z != 0){
                    temp += penalty[x][y];
                }

                if(dist[x][y - 1][next] > cost + temp){
                    dist[x][y - 1][next] = cost + temp;
                    pq.push({cost + temp, x, y - 1, next});
                }
            }

            if(x - 1 >= 0){
                long long temp = (x * 1LL) * (y + 1LL);

                if(z != 0){
                    temp += penalty[x][y];
                }

                if(dist[x - 1][y][next] > cost + temp){
                    dist[x - 1][y][next] = cost + temp;
                    pq.push({cost + temp, x - 1, y, next});
                }
            }
        }

        return -1;
    }
};