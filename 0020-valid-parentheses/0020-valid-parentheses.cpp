class Solution {
public:
    bool isValid(string s) {
        stack<int> st;

        int n = s.size();

        for(int i = 0; i < n; i++){
            char ch = s[i];

            if(ch == '(' || ch == '[' || ch == '{')
                st.push(ch);
            else{
                if((st.empty()) || (st.top() == '(' && ch != ')') || 
                    (st.top() == '[' && ch != ']') ||                 
                        (st.top() == '{' && ch != '}'))
                    return false;

                st.pop();
            }
        }

        if(st.empty())
            return true;
    
        return false;
    }
};