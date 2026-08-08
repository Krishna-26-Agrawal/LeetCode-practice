class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int m = word2.size();
        int n = word1.size();

        vector<int> last(m, -1);

        int j = m - 1;
        for(int i = n - 1; i >= 0 & j >= 0; i--){
            if(word1[i] == word2[j]){
                last[j] = i;
                j--;
            }
        }

        vector<int> ans;
        bool skip = true;
        j = 0;

        for(int i = 0; i < n && j < m; i++){
            if(word1[i] == word2[j]){
                ans.push_back(i);
                j++;
            }
            else if(skip && (j == m - 1 || i < last[j + 1])){
                skip = false;
                ans.push_back(i);
                j++;
            }
        }

        if(j == m){
            return ans;
        }

        return {};
    }
};