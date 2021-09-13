class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0, result = nums.size();
        for(int num : nums) {
            result ^= i;
            result ^= num;
            i++;            
        }
        
        return result;
    }
};