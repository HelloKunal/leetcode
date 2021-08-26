#include <cmath>
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int nS = nums.size();
        unordered_map<int, int> um;
        int sum = 0, res = 0;
        for(int i = 0; i < nS; i++) {
            sum = (sum+nums[i]%k+k)%k;
            res += um[sum];
            if(sum == 0) {
                res++;
            }
            um[sum]++;
        }
        
        return res;
    }
};