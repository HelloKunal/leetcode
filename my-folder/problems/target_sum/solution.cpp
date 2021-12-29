class Solution {
public:
    int n, S;
    map<pair<int, int>, int> cache;
    int DFS(vector<int>& nums, int currSum, int i) {
        auto find = cache.find({i, currSum});
        
        if(find != cache.end()) return find->second;
        
        if(i == n && currSum == S) return 1;
        if(i >= n) return 0;
        
        return cache[{i, currSum}] = DFS(nums, currSum + nums[i], i+1) + DFS(nums, currSum - nums[i], i+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        S = target;
        
        if(n == 0) return 0;
        
        return DFS(nums, 0, 0);
    }
};