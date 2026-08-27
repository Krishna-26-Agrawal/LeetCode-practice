class Solution {
public:
    
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);
        for(char c : s){
            freq[c - 'a']++;
        }

        string result = "";
        function<bool(int, bool)> dfs = [&](int index, bool is_greater){
            if(index == s.length()){
                return is_greater; 
            }

            if(is_greater){
                for(int i = 0; i < 26; i++){
                    while(freq[i] > 0){
                        result += (char)('a' + i);
                        freq[i]--;
                    }
                }

                return true;
            }
            
            char t = target[index];

            if(freq[t - 'a'] > 0){
                freq[t - 'a']--;
                result += t;
                
                if(dfs(index + 1, false)){
                    return true;
                }

                result.pop_back();
                freq[t - 'a']++;
            }
            
            for (int i = t - 'a' + 1; i < 26; i++) {
                if (freq[i] > 0) {
                    freq[i]--;
                    result += (char)('a' + i);
                    dfs(index + 1, true);
                    return true; 
                }
            }

            return false;
        };
        
        dfs(0, false);
        return result;
    }
};