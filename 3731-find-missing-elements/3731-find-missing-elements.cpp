class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minEl = INT_MAX, maxEl = INT_MIN, n = nums.size();

        for(int i : nums){
            maxEl = max(maxEl, i);
            minEl = min(minEl, i);
        }

        vector<int> present(maxEl + 1, 0);
        for(int i : nums){
            present[i] = 1;
        }

        vector<int> ans;
        for(int i = minEl; i <= maxEl; i++){
            if(present[i] == 0){
                ans.push_back(i);
            }
        }

        return ans;
    }
};