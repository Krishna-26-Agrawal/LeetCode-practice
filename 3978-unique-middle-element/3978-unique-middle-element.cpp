class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int midIdx = (n - 1) / 2;

        for(int i = 0; i < n; i++){
            if(i != midIdx && nums[midIdx] == nums[i]){
                return false;
            }
        }

        return true;
    }
};