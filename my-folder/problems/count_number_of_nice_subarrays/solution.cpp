class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int nS = nums.size();
        
        unordered_map<int, int> um;
        um[0] = 1;
        int sum = 0, res = 0;
        for(int i = 0; i < nS; i++) {
            sum += nums[i] % 2;
            res += um[sum-k];
            um[sum]++;
        }
        
        return res;
    }
};