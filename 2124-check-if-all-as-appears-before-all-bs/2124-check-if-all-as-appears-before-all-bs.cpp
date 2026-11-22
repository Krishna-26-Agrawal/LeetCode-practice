class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        int lastA = -1, lastB = -1;
        for(int i = 0; i < n; i++){
            if(s[i] == 'a'){
                lastA = i;
            }
            else{
                if(lastB == -1){
                    lastB = i;
                }
                else if(lastB < lastA){
                    return false;
                }
            }
        }

        if(lastA == -1 || lastB == -1){
            return true;
        }

        return lastB > lastA;
    }
};