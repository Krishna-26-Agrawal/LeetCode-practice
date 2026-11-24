class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 2;
        const long long maxProd = 1e9; 

        for(int i = 0; i < n; i++){
            int prod = 1;
            int tempGcd = 0;
            int tempLcm = 1;

            for(int j = i; j < n; j++){
                if(prod > maxProd / nums[j]){
                    break;
                }
                
                prod *= nums[j];
                tempGcd = gcd(tempGcd, nums[j]);
                tempLcm = lcm(tempLcm, nums[j]);

                if(prod == tempGcd * tempLcm){
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;        
    }
};