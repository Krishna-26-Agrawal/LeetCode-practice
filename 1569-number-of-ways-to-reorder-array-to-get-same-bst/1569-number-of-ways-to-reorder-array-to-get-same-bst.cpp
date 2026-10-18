class Solution {
    long long MOD = 1e9 + 7;
    vector<vector<long long>> v;

    long long dfs(vector<int> &nums){
        int n = nums.size();
        if(n <= 2){
            return 1;
        }

        vector<int> left;
        vector<int> right;
        int temp = nums[0];

        for(int i = 1; i < n; i++){
            if(nums[i] < temp){
                left.push_back(nums[i]);
            }
            else{
                right.push_back(nums[i]);
            }
        }

        long long tempLeft = dfs(left);
        long long tempRight = dfs(right);

        int l = left.size();
        int r = right.size();

        long long curr = v[l + r][l];
        curr = (curr * tempLeft) % MOD;
        curr = (curr * tempRight) % MOD;

        return curr;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        v.assign(n + 1, vector<long long>(n + 1, 0));
        
        for(int i = 0; i <= n; i++){
            v[i][0] = 1;

            for(int j = 1; j <= i; j++){
                v[i][j] = (v[i - 1][j - 1] + v[i - 1][j]) % MOD;
            }
        }

        long long ans = dfs(nums);
        return (ans - 1 + MOD) % MOD;
    }
};