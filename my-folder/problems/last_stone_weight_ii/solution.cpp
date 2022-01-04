class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int s = 0;
        for(int i : stones) s += i;
        vector<vector<bool>> knapsackDP(n+1, vector<bool> ((s/2)+1, false));
        knapsackDP[0][0] = true;
        for(int i = 0; i < n; i++) {
            knapsackDP[i][0] = true;
        }
        
        int omax = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= s/2; j++) {
                knapsackDP[i][j] = knapsackDP[i-1][j];
                if(j >= stones[i-1]) {
                    knapsackDP[i][j] = knapsackDP[i-1][j] || knapsackDP[i-1][j-stones[i-1]];
                }
                if(knapsackDP[i][j] == true) {
                    omax = max(omax, j);
                }
            }
        }
        
        return s-(2*omax);
    }
};