class Solution {
public:
    int minMoves(vector<int>& nums) {
        int count = 0;
        int maxEl = INT_MIN;
        for(int i : nums){
            maxEl = max(maxEl, i);
        }

        for(int i : nums){
            count += (maxEl - i);
        }

        return count;
    }
};