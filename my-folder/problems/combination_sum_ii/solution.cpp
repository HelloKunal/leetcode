class Solution {
public:
    void csUtil(int curr, vector<int>& candidates, vector<vector<int>>& res, vector<int>& tempRes, int target) {
        if(!target) {
            res.push_back(tempRes);
            return;
        }
        
        for(int i = curr; i < candidates.size(); i++) {
            if(i != curr && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break; // iincreasing order, later elements will always be bigger
            
            tempRes.push_back(candidates[i]);
            csUtil(i+1, candidates, res, tempRes, target-candidates[i]);
            tempRes.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> tempRes;
        vector<vector<int>> res;
        csUtil(0, candidates, res, tempRes, target);
        return res;
    }
};