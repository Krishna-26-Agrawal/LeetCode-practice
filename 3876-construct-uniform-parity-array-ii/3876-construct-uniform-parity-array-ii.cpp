class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(), nums1.end());
        int minOdd = INT_MAX, n = nums1.size();
        int xe = 0, xo = 0;
        for(int i : nums1){
            xe = (i % 2 == 0) ? xe + 1 : xe;
            xo = (i % 2 == 0) ? xo : xo + 1;

            if(minOdd != INT_MAX){
                if(i % 2 == 0){
                    xo++;
                }
                else{
                    xe++;
                }
            }

            if(i % 2 != 0){
                minOdd = min(minOdd, i);
            }
        }

        return (xe == n) || (xo == n);
    }
};