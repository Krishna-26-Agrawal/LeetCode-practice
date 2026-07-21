class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        int count = 0;
        int gain = 0;
        int x = INT_MIN;

        for(int i = 0; i < n;){
            int j = i + 1;

            while(j < n && s[j] == s[i]){
                j++;
            }

            int len = j - i;

            if(s[i] == '1'){
                count += len;
            }
            else{
                gain = max(gain, x + len);
                x = len;
            }

            i = j;
        }

        return count + gain;
    }
};