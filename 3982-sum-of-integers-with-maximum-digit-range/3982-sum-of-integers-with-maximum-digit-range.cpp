class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        vector<vector<int>> arr(10);
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            int m = nums[i];
            int maxi = INT_MIN, mini = INT_MAX;
            
            while(m > 0){
                int digit = m % 10;
                
                maxi = max(maxi, digit);
                mini = min(mini, digit);

                m /= 10;
            }
            
            arr[maxi - mini].push_back(nums[i]);
        }

        int sum = 0;
        for(int i = 9; i >= 0; i--){
            if(!arr[i].empty()){
                for(int i : arr[i]){
                    sum += i;
                }

                break;
            }
        }

        return sum;
    }
};