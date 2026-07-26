class Solution {
public:
    int largestInteger(int n, int s) {
        int ans = 0;
        while(n--){
            for(int i = 9; i >= 0; i--){
                if(s - i >= 0){
                    ans = ans * 10 + i;
                    s -= i;
                    break;
                }
            }
        }

        if(s > 0){
            return -1;
        }

        return ans;
    }
};