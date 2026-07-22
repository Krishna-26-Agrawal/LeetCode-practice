class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }

        int n = s.size();
        vector<vector<char>> rowDis(numRows);
        bool x = true;

        for(int i = 0; i < n;){
            int t = (x) ? numRows : (numRows - 2);

            while(t){
                int idx = (x) ? numRows - t : t;
                t--;

                if(i < n)
                    rowDis[idx].push_back(s[i]);
                i++;
            }

            x = !x;
        }

        string result = "";

        for(auto i : rowDis){
            for(char c : i){
                result += c;
            }
        }

        return result;
    }
};