class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> prefix(n + 1, 0);
        for(int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        vector<vector<int>> memo(n, vector<int>(n, -1));

        return solve(0, n - 1, prefix, memo);
    }

    int solve(int i, int j, vector<int> &prefix, vector<vector<int>> &memo){
        if(i == j){
            return 0;
        }
        
        if(memo[i][j] != -1){
            return memo[i][j];
        }

        int maxi = 0;

        for(int k = i; k < j; k++){
            int left = prefix[k + 1] - prefix[i];
            int right = prefix[j + 1] - prefix[k + 1];

            if(left < right){
                maxi = max(maxi, left + solve(i, k, prefix, memo));
            }
            else if(left > right){
                maxi = max(maxi, right + solve(k + 1, j, prefix, memo));
            }
            else{
                maxi = max({maxi, left + solve(i, k, prefix, memo), right + solve(k + 1, j, prefix, memo)});
            }
        }

        return memo[i][j] = maxi;
    }
};