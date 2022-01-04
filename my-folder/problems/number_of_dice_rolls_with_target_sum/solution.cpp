class Solution {
public:
    vector<vector<int>> memo;
    int mod = pow(10, 9) + 7;
    int solve(int n, int k, int target) {
        if(memo[n][target] != -1) return memo[n][target];
        if(n == 1) {
            if(target == 0) return 0;
            if(target > k) return 0;
            return 1;
        }
        
        int total = 0;
        for(int i = 1; i <= k; i++) {
            int left = solve(1, k, i);
            int right = (target - i >= 0) ? solve(n-1, k, target - i) : 0;
            total += (left * right) % mod;
            total %= mod;
        }
        
        return memo[n][target] = total;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        memo.assign(n+1, vector<int> (max(target, k) + 1, -1));
        return solve(n, k, target);
    }
};