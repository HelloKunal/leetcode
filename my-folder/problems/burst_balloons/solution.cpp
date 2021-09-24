class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int numsSize = nums.size();
        vector<vector<int>> dpArray(numsSize, vector<int> (numsSize, 0));
        
        for(int g = 0; g < numsSize; g++) {
            for(int i = 0, j = g; j < numsSize; i++, j++) {
                
                int max_temp = INT_MIN;
                for(int k = i; k <= j; k++) {
                    int left = k == i ? 0 : dpArray[i][k-1];
                    int right = k == j ? 0 : dpArray[k+1][j];
                    int val = nums[k];
                    if(i > 0) {
                        val *= nums[i-1];
                    }
                    if(j < numsSize-1) {
                        val *= nums[j+1];
                    }
                    
                    int total = left + right + val;
                    max_temp = max(total, max_temp);
                }
                
                dpArray[i][j] = max_temp;
            }
        }
        
        return dpArray[0][numsSize-1];
    }
};