class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
int n = nums.size();
        if(k == n){
            int maxEl = -1;
            for(int i : nums){
                maxEl = max(maxEl, i);
            }

            return maxEl;
        }

        unordered_map<int, int> freq;
        for (int i : nums){
            freq[i]++;
        }

        if (k == 1){
            int maxEl = -1;
            for (int i : nums){
                if (freq[i] == 1){
                    maxEl = max(maxEl, i);
                }
            }
            return maxEl;
        }

        int maxEl = -1;
        if(freq[nums[0]] == 1){
            maxEl = max(maxEl, nums[0]);
        }

        if(freq[nums[n - 1]] == 1){
            maxEl = max(maxEl, nums[n - 1]);
        }
        
        return maxEl;
    }
};