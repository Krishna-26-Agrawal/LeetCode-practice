class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        int n = strs.size(), index = 0;

        int minSize = INT_MAX;
        for(int i = 0; i < n; i++){
            minSize = min(minSize, (int)strs[i].size());
        }

        while(minSize--){
            result += strs[0][index];

            for(int i = 1; i < n; i++){
                if(strs[i][index] != result[index]){
                    if(!result.empty())
                        result.pop_back();
                    return result;
                }
            }

            index++;
        }

        return result;
    }
};