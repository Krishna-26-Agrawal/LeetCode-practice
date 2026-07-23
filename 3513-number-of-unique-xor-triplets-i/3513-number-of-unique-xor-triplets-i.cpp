class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2){
            return n;
        }

        int len = 0, temp = n;
        while(temp > 0){
            len++;
            temp >>= 1;
        }

        return 1 << len;
    }
};