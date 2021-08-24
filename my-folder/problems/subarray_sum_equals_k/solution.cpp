class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int nS = nums.size();
        
        int pSum[nS];
        unordered_map<int, int> um;
        int sum = 0, res = 0;
        for(int i = 0; i < nS; i++) {
            sum += nums[i];
            
            if(um.find(sum-k) != um.end()) {
                res += um[sum-k];
            }
            if(sum == k) {
                res++;
            }
            
            um[sum]++;            
        }
        
        return res;        
    }
};