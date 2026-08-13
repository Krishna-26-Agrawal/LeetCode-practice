class Solution {
    set<int> st;
    multiset<int> m;

    void add(int x){
        if(st.count(x)){
            return;
        }

        auto i = st.insert(x).first;
        int l = *prev(i);
        int r = *next(i);

        m.erase(m.find(r - l));
        m.insert(x - l);
        m.insert(r - x);
    }

    void remove(int x){
        if(!st.count(x)){
            return ;
        }

        auto i = st.find(x);
        int l = *prev(i);
        int r = *next(i);

        m.erase(m.find(x - l));
        m.erase(m.find(r - x));
        m.insert(r - l);

        st.erase(i);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        int k = queryCharacters.length();

        st.insert(0);
        st.insert(n);
        m.insert(n);

        for(int i = 1; i < n; i++){
            if(s[i] != s[i - 1]){
                add(i);
            }
        }

        vector<int> ans;

        for(int i = 0; i < k; i++){
            int idx = queryIndices[i];
            char c = queryCharacters[i];

            if(s[idx] != c){
                s[idx] = c;

                if(idx > 0){
                    if(s[idx] == s[idx - 1]){
                        remove(idx);
                    }
                    else{
                        add(idx);
                    }
                }

                if(idx + 1 < n){
                    if(s[idx] == s[idx + 1]){
                        remove(idx + 1);
                    }
                    else{
                        add(idx + 1);
                    }
                }
            }

            ans.push_back(*m.rbegin());
        }

        return ans;
    }
};