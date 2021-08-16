class Solution {
public:
    void rec (int index, int target, vector<int> &candidates, vector<vector<int>> &res, vector<int> &temp_res)
    {
        if (target == 0)
        {
            res.push_back (temp_res);
            return;
        }
        
        for (int i = index, y = candidates.size(); i < y; i++)
        {
            if (i > index && candidates[i] == candidates[i-1]) continue;
            if (candidates[i] > target) break;
                
            temp_res.push_back(candidates[i]);
            rec (i+1, target-candidates[i], candidates, res, temp_res);
            temp_res.pop_back();                     
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp_res;
        sort (candidates.begin(), candidates.end());
        
        rec (0, target, candidates, res, temp_res);        
        return res;
    }
};