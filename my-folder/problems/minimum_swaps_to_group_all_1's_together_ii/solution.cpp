class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int countOnes = 0;
        for(int i : nums) {
            if(i == 1) countOnes++;
        }
        
        int countOnesInWindow = 0;
        for(int i = 0; i < nums.size() && i < countOnes; i++) {
            if(nums[i] == 1) countOnesInWindow++;
        }
        
        int Swaps = countOnes - countOnesInWindow;
        int MinSwaps = Swaps;
        for(int i = countOnes; i < nums.size()+countOnes; i++) {
            if(i < nums.size()) {
                if(nums[i - countOnes] == 1) countOnesInWindow--;
                if(nums[i] == 1) countOnesInWindow++;                
            } else {
                if(nums[i - countOnes] == 1) countOnesInWindow--;
                if(nums[i - nums.size()]) countOnesInWindow++;
            }
            Swaps = countOnes - countOnesInWindow;
            MinSwaps = min(Swaps, MinSwaps);
        }
        
        return MinSwaps;
    }
};