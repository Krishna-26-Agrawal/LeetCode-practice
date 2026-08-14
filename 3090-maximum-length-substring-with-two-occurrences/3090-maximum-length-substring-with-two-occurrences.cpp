class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0;
        int maxLen = 0;
        vector<int> freq(26, 0);

        while(r < n){
            char c = s[r];
            freq[c - 'a']++;

            while(l < r && freq[c - 'a'] > 2){
                freq[s[l] - 'a']--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};