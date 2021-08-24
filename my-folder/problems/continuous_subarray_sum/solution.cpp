class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int nS = nums.size();
        int sum = 0;
        unordered_map<int, int> um;
        um[0] = -1;
        for(int i = 0; i < nS; i++) {
            sum += nums[i];
            
            sum %= k;
            
            if (um.find(sum) != um.end()) {
                if(i - um.find(sum)->second >= 2) {
                    return true;
                }
            } else {
                um[sum] = i;
            }
        }
        
        return false;
    }
};