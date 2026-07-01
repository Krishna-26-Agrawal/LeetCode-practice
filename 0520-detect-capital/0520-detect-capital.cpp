class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size(), count = 0, index = -1;

        for(int i = 0; i < n; i++){
            int diff = 'A' - word[i];
            if(diff <= 0 && diff >= -25){
                count++;
                index = i;
            }
        }

        return (count == 0) || (count == 1 && index == 0) || (count == n);
    }
};