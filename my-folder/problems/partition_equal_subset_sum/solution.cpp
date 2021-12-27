class Solution {
public:
    vector<vector<int>> memo;
    bool rec(vector<int>& nums, int i, int target) {
        
        if(target <= 0) {
            if(!target) return true; 
            return false;
        }
        
        if(i >= nums.size()) return false;
        
        if(memo[i][target] != -1) return memo[i][target];
        
        return memo[i][target] = rec(nums, i+1, target - nums[i]) || rec(nums, i+1, target);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int a : nums) sum += a;
        
        if(sum % 2 == 1) return false;
        else {
            sum /= 2;
            memo.assign(nums.size()+1, vector<int> (sum+1, -1));
            return rec(nums, 0, sum);
        }
        
        
    }
};