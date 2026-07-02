class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i < n; i++){
            int comp = target - nums[i];

            if(m.find(comp) != m.end()){
                ans.push_back(i);
                ans.push_back(m[comp]);

                return ans;
            }

            m[nums[i]] = i;
        }

        return {};
    }
};