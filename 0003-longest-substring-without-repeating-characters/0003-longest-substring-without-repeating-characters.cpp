class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0;
        int maxLen = 0;

        vector<int> m(256, -1);
        
        while(r < n){
            if(m[s[r]] != -1){
                l = max(m[s[r]] + 1, l);
            }

            m[s[r]] = r;
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        
        return maxLen;
    }
};