class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        long long N = abs(n);
        while(N > 0) {
            if(N % 2 == 0) {
                x *= x;
                N /= 2;
            } else {
                res *= x;
                N -= 1;
            }
        }
        
        if(n < 0) return 1/res;
        else return res;
    }
};