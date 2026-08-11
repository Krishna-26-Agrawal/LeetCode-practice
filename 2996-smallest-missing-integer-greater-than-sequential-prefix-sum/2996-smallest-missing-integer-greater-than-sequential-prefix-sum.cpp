class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefixSum = nums[0], n = nums.size();
        for (int i = 1; i < n; i++){
            if (nums[i] == nums[i - 1] + 1){
                prefixSum += nums[i];
            }
            else{
                break; 
            }
        }
        
        unordered_set<int> numSet(nums.begin(), nums.end());
        int target = prefixSum;
        while (numSet.count(target)) {
            target++;
        }
        
        return target;
    }
};