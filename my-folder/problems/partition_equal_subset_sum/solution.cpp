class Solution {
public:
    vector<vector<int>> memo;
    bool subsetSumUtil(int curr, int n, int sum, int target, vector<int>& nums) {
        if(curr == n) {
            if(sum == target) return true;
            else return false;
        }
        if(memo[curr][sum] != -1) return memo[curr][sum];
        
        return memo[curr][sum] = subsetSumUtil(curr+1, n, sum+nums[curr], target, nums) || 
        subsetSumUtil(curr+1, n, sum, target, nums);
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i : nums) sum += i;
        if(sum % 2 == 1) return false;
        else {
            int newsum = sum/2;
            memo.assign(nums.size(), vector<int> (sum+1, -1));
            return subsetSumUtil(0, nums.size(), 0, newsum, nums);
        }
    }
};