class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        vector<int> suffix(n + 1, 0);

        for(int i = 0; i < n; i++){
            prefix[i + 1] = max(prefix[i], nums[i]);
        }

        suffix[n] = nums[n - 1];
        for(int i = n - 1; i >= 1; i--){
            suffix[i] = min(suffix[i + 1], nums[i - 1]);
        }

        for(int i = 0; i < n; i++){
            int inst = prefix[i + 1] - suffix[i + 1];
            if(inst <= k){
                return i;
            }
        }

        return -1;
    }
};