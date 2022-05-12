class Solution {
public:
    set<vector<int>> st;
    
    void permute(vector<int> &nums, int l, int r) {
        if(l == r) {
            st.insert(nums);
        }
        
        for(int i = l; i <= r; i++) {
            
            swap(nums[l], nums[i]);
            
            permute(nums, l+1, r);
            
            swap(nums[l], nums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {        
        permute(nums, 0, nums.size()-1);
        
        vector<vector<int>> res;
        for(auto i : st) {
            res.push_back(i);
        }
        
        return res;
    }
};