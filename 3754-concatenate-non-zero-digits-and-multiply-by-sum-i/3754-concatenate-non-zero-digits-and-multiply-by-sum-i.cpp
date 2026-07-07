class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0, newNum = 0;
        int factor = 1;
        int m = n;
        while(m > 0){
            int digit = m % 10;
            m /= 10;

            if(digit != 0){
                newNum = newNum + factor * digit;
                sum += digit;
                factor *= 10;
            }
        }

        return sum * newNum;
    }
};