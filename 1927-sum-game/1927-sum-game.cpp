class Solution {
public:
    bool sumGame(string num) {
        vector<int> indexes;
        int n = num.size();
        int sumDiff = 0;
        int quesDiff = 0;

        for(int i = 0; i < n / 2; i++){
            if(num[i] == '?'){
                quesDiff++;
            }
            else{
                sumDiff += (num[i] - '0');
            }
        }

        for(int i = n / 2; i < n; i++){
            if(num[i] == '?'){
                quesDiff--;
            }
            else{
                sumDiff -= (num[i] - '0');
            }
        }

        return (sumDiff * 2 + quesDiff * 9) != 0;

        return false;
    }
};