class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int g = INT_MIN, sg = INT_MIN;

        for(int i : nums){
            if(i >= g){
                sg = g;
                g = i;
            }
            else if(i > sg){
                sg = i;
            }
        }

        return (g - 1) * (sg - 1);
    }
};