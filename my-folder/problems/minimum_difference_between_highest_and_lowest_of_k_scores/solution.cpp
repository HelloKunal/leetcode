class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = INT_MAX;
        for(int i = 0, y = nums.size(); i < y-k+1; i++) {
            res = min(res, nums[k-1+i]-nums[i]);
        }
        return res;
    }
};