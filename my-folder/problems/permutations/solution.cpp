class Solution {
public:
    void nextP(vector<int>& nums) {
        int index = -1, i, l;
        int n = nums.size();
        for(i = n-2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) break;
        }
        
        if(i < 0) reverse(nums.begin(), nums.end());
        else {
            for(l = n-1; l > i; l--) {
                if(nums[l] > nums[i]) break;
            }
            
            swap(nums[i], nums[l]);
            reverse(nums.begin() + i + 1, nums.end());
        }
    }
    
    int fact(int n) {
        if(n == 1) return 1;
        return n*fact(n-1);
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int k = fact(nums.size());
        vector<vector<int>> ret;
        for(int i = 0; i < k; i++) {
            ret.push_back(nums);
            nextP(nums);
        }
        
        return ret;
    }
};