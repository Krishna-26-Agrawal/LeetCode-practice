class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string temp = s;
        sort(temp.begin(), temp.end());
        if(temp == s){
            return 0;
        }

        if(n == 2){
            return -1;
        }

        char mini = 'z', maxi = 'a';
        for(char c : s){
            mini = min(mini, c);
            maxi = max(maxi, c);
        }

        if(s[0] == mini || s[n - 1] == maxi){
            return 1;
        }

        for(int i = 1; i < n - 1; i++){
            if(s[i] == mini || s[i] == maxi){
                return 2;
            }
        }

        return 3;
    }
};