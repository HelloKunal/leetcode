class Solution {
public:
    int memoArray[1<<20] = {};
    bool canIWin(int M, int T) {
        int totalSum = M*(M+1)/2;
        
        if(T < 2) return true;        
        if(totalSum < T) return false;
        if(totalSum == T) return M%2;
        
        return canIWinUtil(M, T, 0);
    }
    
    bool canIWinUtil(int M, int T, int K) {
        if(memoArray[K] != 0) return memoArray[K] > 0;
        if(T <= 0) return false;
        
        for(int i = 0; i < M; i++) {
            if(!(K&(1<<i)) && !canIWinUtil(M, T-(i+1), K|(1<<i))) {
                memoArray[K] = 1;
                return true;
            }
        }
        
        memoArray[K] = -1;
        return false;
    }
};