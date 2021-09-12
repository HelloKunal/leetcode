class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int numSize = nums.size();
        vector<int> dpArr(numSize);
        vector<int> countArr(numSize, 1);
        int omax = 0;
        for(int i = 0; i < numSize; i++) {
            int t = 0, c = 0;
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    if(dpArr[j] + 1 > dpArr[i]) {
                        dpArr[i] = dpArr[j] + 1;
                        countArr[i] = countArr[j];
                    } else if(dpArr[j] + 1 == dpArr[i]) {
                        countArr[i] += countArr[j];
                    }
                }
            }
            omax = max(omax, dpArr[i]);
        }
        
        int res = 0;
        for(int i = 0; i < numSize; i++) {
            if(dpArr[i] == omax) res += countArr[i];
        }
        return res;
    }
};