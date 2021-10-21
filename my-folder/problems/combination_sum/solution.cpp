class Solution {
public:
    
    void combinationSumUtil(int curr, int n, vector<int>& temp, vector<int>& candidates, int sum, int target, vector<vector<int>>& res) {
        if(curr == n) {
            if(sum == target) res.push_back(temp);
            return;
        }
        
        if(candidates[curr] <= target - sum) {
            temp.push_back(candidates[curr]);
            combinationSumUtil(curr, n, temp, candidates, sum+candidates[curr], target, res);
            temp.pop_back();
        }
        
        combinationSumUtil(curr+1, n, temp, candidates, sum, target, res);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        combinationSumUtil(0, candidates.size(), temp, candidates, 0, target, res);
        return res;        
    }
};