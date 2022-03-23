class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int indexOne = -1;
        for(int i = nums.size()-2; i >= 0; i--) {
            if(nums[i+1] > nums[i]) {
                indexOne = i;
                break;
            }
        }
        
        if(indexOne == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        for(int i = nums.size()-1; i >= 0; i--) {
            if(nums[i] > nums[indexOne]) {
                swap(nums[i], nums[indexOne]);
                break;
            }
        }
        
        sort(nums.begin()+indexOne+1, nums.end());
    }
};