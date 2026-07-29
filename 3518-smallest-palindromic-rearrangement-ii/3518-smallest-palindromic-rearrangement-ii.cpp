class Solution {
public:
    long long ncr(int n, int r, int k) {
        r = min(r, n-r);

        long long result = 1;

        for(int i = 1; i <= r; i++) {
            result = result * (n - r + i)/i;

            if(result >= k) 
                return k;
        }

        return result;
    }

    string smallestPalindrome(string s, int k) {
        int n = s.length();
        if(n == 1){
            return s;
        }

        string mid = "";

        vector<int> count(26, 0);
        for(char c : s){
            count[c - 'a']++;
        }
        
        vector<int> freq(26, 0);
        for(int i = 0; i < 26; i++){
            freq[i] = count[i] / 2;

            if(count[i] % 2 != 0){
                mid += ('a' + i);
            }
        }

        string left = "";
        int sz = n/2;

        for(int i = 0; i < sz; i++){
            bool placed = false;

            for(int j = 0; j < 26; j++){
                if(freq[j] > 0){
                    freq[j]--;

                    long long ways = 1;
                    int total = 0;

                    for(int c = 0; c < 26; c++){
                        if(freq[c] > 0){
                            total += freq[c];
                        }
                    }

                    for(int c = 0; c < 26; c++){
                        if(freq[c] > 0){
                            ways *= ncr(total, freq[c], k);
                            total -= freq[c];
                        }

                        if(ways >= k){
                            break;
                        }
                    }

                    if(ways >= k){
                        left += ('a' + j);
                        placed = true;
                        break;
                    }

                    k -= ways;
                    freq[j]++;
                }
            }

            if(!placed){
                return "";
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if(left.empty()){
            return "";
        }

        return left + mid + right;
    }
};