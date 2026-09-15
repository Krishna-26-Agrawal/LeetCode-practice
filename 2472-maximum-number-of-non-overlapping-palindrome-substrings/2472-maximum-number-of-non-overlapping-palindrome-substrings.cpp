class Solution {
public:
    bool check(string s, int l, int r){
        while(l < r){
            if(s[l] != s[r]){
                return false;
            }

            l++;
            r--;
        }

        return true;
    }

    int maxPalindromes(string s, int k) {
        int n = s.length();
        int count = 0;
        int i = 0;

        while(i <= n - k){
            if(check(s, i, i + k - 1)){
                count++;
                i += k;
            }
            else if(i + k < n && check(s, i, i + k)){
                count++;
                i += k + 1;
            }
            else{
                i++;
            }
        }

        return count;
    }
};