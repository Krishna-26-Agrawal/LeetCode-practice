class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffix(n, 0);
        suffix[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--){
            suffix[i] = min(suffix[i + 1], nums[i]);
        }

        int maxEl = INT_MIN;
        for(int i = 0; i < n; i++){
            maxEl = max(maxEl, nums[i]);
            int score = maxEl - suffix[i];

            if(score <= k){
                return i;
            }
        }

        return -1;
    }
};