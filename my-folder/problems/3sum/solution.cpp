class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int numLen = nums.size();
        vector<vector<int>> res;
        int target = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < numLen; i++) {
            if(i != 0 && nums[i] == nums[i-1]) continue;
            int start = i+1, end = numLen-1;
            while(start < end) {
                if(start != i+1 && nums[start] == nums[start-1]) {
                    start++;
                    continue;
                }
                long int sum = 1L*nums[i] + 1L*nums[start] + 1L*nums[end];
                if(sum == target) {
                    res.push_back({nums[i], nums[start], nums[end]});
                    start++;
                    end--;
                } else if(sum < target) {
                    start++;
                } else {
                    end--;
                }
            }            
        }
        
        return res;
    }
};