class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        long long a = 0, b = 0, c = 0;
        for(int i = 1; i <= n; i++){
            long long curr = costs[i - 1];
            long long temp = c + curr + 1;

            if(i >= 2){
                temp = min(temp, b + curr + 4);
            }

            if(i >= 3){
                temp = min(temp, a + curr + 9);
            }

            a = b;
            b = c;
            c = temp;
        }

        return c;
    }
};