class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        set<int> resSet;
        for(int i = 0; i < n; i++) {
            if(nums[i] == key) {
                for(int j = max(0, i-k); j <= min(n-1, i+k); j++) resSet.insert(j);
            }
        }
        
        
        vector<int> res(resSet.begin(), resSet.end());
        return res;
            
    }
};