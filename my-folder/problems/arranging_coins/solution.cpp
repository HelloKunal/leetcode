class Solution {
public:
    int arrangeCoins(int n) {
        long long int i = -1 + pow(1 + 8LL*n, 0.5);
        i /= 2;
        return i;
    }
};