class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minVal = INT_MAX, maxVal = INT_MIN;
        for(int i : nums){
            maxVal = max(maxVal, i);
            minVal = min(minVal, i);
        }

        return gcd(minVal, maxVal);
    }
};