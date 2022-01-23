class Solution {
public:
    int countElements(vector<int>& nums) {
        int minEle = *min_element(nums.begin(), nums.end()), maxEle = *max_element(nums.begin(), nums.end());
        int minCount = count(nums.begin(), nums.end(), minEle);
        int maxCount = count(nums.begin(), nums.end(), maxEle);
        int res = nums.size() - minCount - maxCount;
        return max(res, 0);
    }
};