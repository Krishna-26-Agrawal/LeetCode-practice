class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> one1;
        vector<pair<int, int>> one2;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(img1[i][j] == 1){
                    one1.push_back({i, j});
                }
                if(img2[i][j] == 1){
                    one2.push_back({i, j});
                }
            }
        }

        vector<vector<int>> temp(2 * n, vector<int>(2 * n, 0));
        int count = 0;
        for(auto i : one1){
            for(auto j : one2){
                int row = j.first - i.first;
                int col = j.second - i.second;

                temp[row + n][col + n]++;

                count = max(count, temp[row + n][col + n]);
            }
        }
        
        return count;                
    }
};