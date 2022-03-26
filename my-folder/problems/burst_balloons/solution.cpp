class Solution {
public:
    vector<vector<int>> dpArr;
    int maxCoinsUtil(vector<int>& nums, int i, int j) {
        if(i >= j) return 0;
        if(dpArr[i][j] != -1) return dpArr[i][j];
        int res = 0;
        for(int k = i; k <= j-1; k++) {
            int tempoRes = maxCoinsUtil(nums, i, k) + maxCoinsUtil(nums, k+1, j) + nums[i-1] * nums[k] * nums[j];
            res = max(tempoRes, res);
        }
        
        return dpArr[i][j] = res;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        dpArr.assign(nums.size(), vector<int> (nums.size(), -1));
        return maxCoinsUtil(nums, 1, nums.size()-1);
    }
};