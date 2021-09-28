class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> dpArray;
        dpArray[0] = 1;
        for(int num : nums) {
            unordered_map<int, int> dpArray2;
            for(auto temp : dpArray) {
                int tempkey = temp.first;
                int key1 = tempkey-num, key2 = tempkey+num;
                dpArray2[key1] += dpArray[tempkey];
                dpArray2[key2] += dpArray[tempkey];
            }
            dpArray = dpArray2;
        }
        
        return dpArray[target];
    }
};