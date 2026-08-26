class Solution {
public:
    bool check(string t, string result, int len){
        int index = -1;
        for(int i = 0; i < len; i++){
            if(result[i] != t[i]){
                index = i;
                break;
            }
        }

        return (index != -1 && t[index] < result[index]) ? true : false;
    }

    string shortestBeautifulSubstring(string s, int k) {
        int count = 0, n = s.size();
        string result = s;

        for(int i = 0; i < n; i++) count += (s[i] - '0');
        if(count < k) return "";

        count = 0;

        for(int l = 0, r = 0; r < n; r++){
            count += (s[r] - '0');
            while(count > k || s[l] == '0'){
                count -= (s[l] - '0');
                l++;
            }

            if(count == k){
                string t = s.substr(l, r - l + 1);
                if(t.length() < result.length() || (t.length() == result.length() && check(t, result, r - l + 1))){
                    result = t;
                }
            }
        }

        return result;
    }
};