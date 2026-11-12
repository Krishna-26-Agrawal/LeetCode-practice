class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 1;
        int great = 1, less = 1;
        int maxLen = 1;
        while(r < n){
            if(nums[r] > nums[r - 1]){
                great++;
                less = 1;
            }
            else if(nums[r] < nums[r - 1]){
                less++;
                great = 1;
            }
            else{
                great = 1;
                less = 1;
            }

            maxLen = max(maxLen, max(great, less));
            r++;
        }
        
        return maxLen;
    }
};