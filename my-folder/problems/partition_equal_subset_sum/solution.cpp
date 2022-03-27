class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int sumNums = 0;
        for(int i : nums) sumNums += i;
        
        if(sumNums % 2 == 1) return false;
        int oneSum = sumNums / 2;
        
        vector<vector<bool>> dpArr(nums.size()+1, vector<bool> (oneSum+1));
        for(int j = 0; j <= oneSum; j++) dpArr[0][j] = false;
        for(int i = 0; i <= nums.size(); i++) dpArr[i][0] = true;
        
        for(int i = 1; i <= nums.size(); i++) {
            for(int j = 1; j <= oneSum; j++) {
                if(nums[i-1] <= j) {
                    dpArr[i][j] = dpArr[i-1][j - nums[i-1]] || dpArr[i-1][j];
                } else {
                    dpArr[i][j] = dpArr[i-1][j];
                }
            }
        }
        
        return dpArr[nums.size()][oneSum];
    }
};