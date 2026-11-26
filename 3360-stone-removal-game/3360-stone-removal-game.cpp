class Solution {
public:
    bool canAliceWin(int n) {
        int count = 10;
        bool alice = true;

        while (n >= count) {
            n -= count;
            count--;
            alice = !alice;
        }

        return !alice;
    }
};