class Solution {
public:
    vector<int> ext(int n){
        vector<int> ans(3, -1);
        int k = 2;
        while(n > 0){
            ans[k--] = n % 10;
            n /= 10;
        }

        return ans;
    }

    int totalNumbers(vector<int>& digits) {
        vector<int> digit(10, 0);
        for(int i : digits){
            digit[i]++;
        }

        int count = 0;
        for(int i = 100; i <= 998; i+=2){
            vector<int> temp = ext(i);
            digit[temp[0]]--;
            digit[temp[1]]--;
            digit[temp[2]]--;
            bool isValid = true;

            for(int j = 0; j < 10; j++){
                if(digit[j] < 0){
                    isValid = false;
                    break;
                }
            }

            count = (isValid) ? count + 1 : count;
            digit[temp[0]]++;
            digit[temp[1]]++;
            digit[temp[2]]++;
        }

        return count;
    }
};