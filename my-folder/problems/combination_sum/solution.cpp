class Solution {
public:
    void Rec (int index, int target, vector<int> &candidates, list<list<int>> &ans, list<int> &temp_ans)
    {   
        if (index >= candidates.size())
        {
            if (target == 0)
            {
                ans.push_back(temp_ans);
            }     
            return;
        }
        
        if (candidates[index] <= target)
        {
            temp_ans.push_back(candidates[index]);
            Rec (index, target-candidates[index], candidates, ans, temp_ans);
            temp_ans.pop_back();
        }
        Rec (index+1, target, candidates, ans, temp_ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        list<list<int>> ans;
        list<int> temp_ans;
        
        Rec (0, target, candidates, ans, temp_ans);
        vector<vector<int>> result;
        for (auto i : ans)
        {
            result.push_back(vector<int> (i.begin(), i.end()));
        }
        return result;        
    }
};