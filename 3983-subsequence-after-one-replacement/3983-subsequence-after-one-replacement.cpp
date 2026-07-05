class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        if(n > m){
            return false;
        }

        vector<int> pref(n, -1);
        vector<int> suff(n, -1);
        
        int j = 0;
        for(int i = 0; i < n; i++){
            while(j < m && t[j] != s[i]){
                j++;
            }

            if(j == m){
                break;
            }

            pref[i] = j;
            j++;
        }

        j = m - 1;
        for(int i = n - 1; i >= 0; i--){
            while(j >= 0 && t[j] != s[i]){
                j--;
            }

            if(j < 0){
                break;
            }

            suff[i] = j;
            j--;
        }

        for(int i = 0; i < n; i++){
            bool left = (i == 0) || (pref[i - 1] != -1);
            bool right = (i == n - 1) || (suff[i + 1] != -1);

            if(left && right){
                int l = (i == 0) ? -1 : pref[i - 1];
                int r = (i == n - 1) ? m : suff[i + 1];

                if(r - l > 1){
                    return true;
                }
            }
        }

        return false;
    }
};