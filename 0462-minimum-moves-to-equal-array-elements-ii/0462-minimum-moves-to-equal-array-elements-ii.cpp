class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = n - 1;
        int count = 0;
        while(l < r){
            count += (nums[r] - nums[l]);
            l++;
            r--;
        }

        return count;
    }
};