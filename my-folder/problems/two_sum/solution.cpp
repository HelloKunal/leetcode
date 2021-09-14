class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        for(int i = 0; i < nums.size(); i++) {
            if(um.find(nums[i]) != um.end()) {
                vector<int> res;
                res.push_back(um[nums[i]]);
                res.push_back(i);
                return res;
            }
            um[target-nums[i]] = i;
        }
        
        return {};
    }
};