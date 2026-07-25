class Solution {
public:
    int maxProduct(int n) {
        int greatest = -1, secondGreatest = -1;
        while(n > 0){
            int digit = n % 10;
            n /= 10;

            if(digit >= greatest){
                secondGreatest = greatest;
                greatest = digit;
            }
            else if(digit < greatest && digit > secondGreatest){
                secondGreatest = digit;
            }
        }

        return greatest * secondGreatest;
    }
};