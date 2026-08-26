class Solution {
public:
    bool check(string t, string result, int len){
        // cout << "inside check = " << t << " " << result << endl;
        for(int i = 0; i < len; i++){
            // cout << "t[i] = " << t[i] << ", result[i] = " << result[i] << endl;
            if(result[i] != t[i]){
                if(t[i] < result[i]){
                    return true;
                }
                else{
                    return false;
                }
            }
        }

        return false;
    }

    string shortestBeautifulSubstring(string s, int k) {
        int count = 0;
        int l = 0, r = 0;
        int maxLen = 0;
        int n = s.size();
        string result = s;

        for(int i = 0; i < n; i++){
            count += (s[i] - '0');
        }

        if(count < k){
            return "";
        }

        count = 0;

        while(r < n){
            count += (s[r] - '0');
            while(count > k || s[l] == '0'){
                count -= (s[l] - '0');
                l++;
            }

            if(count == k){
                string t = s.substr(l, r - l + 1);
                // cout << "outside t = " << t << ", result = " << result << endl;
                if(t.length() < result.length() || (t.length() == result.length() && check(t, result, r - l + 1))){
                    // cout << "t = " << t << ", for l = " << l << endl;
                    result = t;
                }
            }

            // cout << endl;
            r++;
        }

        return result;
    }
};