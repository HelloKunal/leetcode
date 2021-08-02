class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> vnums;
        for (int i = 0; i < n; i++)
        {
            vnums.push_back(make_pair(nums[i], i));
        }
        sort (vnums.begin(), vnums.end());
        int start = 0, end = n-1;
        vector<int> ans;
        while (start < end)
        {
            if (vnums[start].first + vnums[end].first == target)
            {
                ans.push_back(vnums[start].second);
                ans.push_back(vnums[end].second);
                return ans;
            }
            else if (vnums[start].first + vnums[end].first > target)
            {
                end--;
            }
            else
            {
                start++;
            }
        }
        return ans;
    }
};