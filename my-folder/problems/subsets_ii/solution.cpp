class Solution {
public:
    void subsetsUtil(int curr, int n, vector<int>& arr, vector<int>& nums, vector<vector<int>> &res) {
        res.push_back(arr);
        for(int i = curr; i < n; i++) {
            if(i != curr && nums[i] == nums[i-1]) continue;
            
            arr.push_back(nums[i]);
            subsetsUtil(i+1, n, arr, nums, res);
            arr.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        subsetsUtil(0, nums.size(), temp, nums, res);
        return res;
    }
};