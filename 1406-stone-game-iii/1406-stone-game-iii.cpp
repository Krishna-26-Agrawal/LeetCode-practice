class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        int x1 = 0, x2 = 0, x3 = 0;
        for(int i = n - 1; i >= 0; i--){
            int sum = 0, maxDiff = INT_MIN;

            sum += stoneValue[i];
            maxDiff = max(maxDiff, sum - x1);

            if(i + 1 < n){
                sum += stoneValue[i + 1];
                maxDiff = max(maxDiff, sum - x2);
            }

            if(i + 2 < n){
                sum += stoneValue[i + 2];
                maxDiff = max(maxDiff, sum - x3);
            }

            x3 = x2;
            x2 = x1;
            x1 = maxDiff;
        }

        if(x1 > 0){
            return "Alice";
        }
        else if(x1 < 0){
            return "Bob";
        }

        return "Tie";
    }
};