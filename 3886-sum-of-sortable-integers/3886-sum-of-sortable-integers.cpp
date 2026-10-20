class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefix[i] = max(prefix[i - 1], nums[i]);
        }

        vector<int> suffix(n);
        suffix[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--){
            suffix[i] = std::min(suffix[i + 1], nums[i]);
        }

        vector<int> drop(n, 0);
        for(int i = 0; i < n - 1; i++){
            drop[i + 1] = drop[i] + (nums[i] > nums[i + 1] ? 1 : 0);
        }
        
        int sum = 0;
        for(int k = 1; k <= n; k++){
            if (n % k != 0){
                continue;
            }
            
            bool isSortable = true;
            int num = n / k;
            for(int i = 0; i < num; i++){
                int l = i * k;
                int r = l + k - 1;
                int drops = drop[r] - drop[l];

                if(k > 1 && nums[r] > nums[l]){
                    drops++;
                }

                if(drops > 1){
                    isSortable = false;
                    break;
                }

                if(i < num - 1){
                    if(prefix[r] > suffix[r + 1]){
                        isSortable = false;
                        break;
                    }
                }
            }
            
            if(isSortable){
                sum += k;
            }
        }
        
        return sum; 
    }
};