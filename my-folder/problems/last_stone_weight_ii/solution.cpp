class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        bitset<1501> dp = {1};
        int sumA = 0;
        for(int stone : stones) {
            sumA += stone;
            for(int i = min(1500, sumA); i >= stone; i--) {
                dp[i] = dp[i] + dp[i-stone];
            }
        }
        for(int i = sumA/2; i >= 0; i--) {
            if(dp[i]) return sumA - i - i;
        }
        return 0;
    }
};