class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> DP(10001, 0);
        int maxI = 0;
        for(int i : nums) {
            DP[i] += i;
            maxI = max(maxI, DP[i]);
        }
        
        int v1 = DP[1];
        int v2 = max(v1, DP[2]);
        for(int i = 3; i <= maxI; i++) {
            int tmp = v2;
            v2 = max(v2, v1 + DP[i]);
            v1 = tmp;
        }
        
        return v2;
    }
};