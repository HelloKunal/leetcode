class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int MaxConOnes = 0, MaxOnes = 0;
        for(int i : nums) {
            if(i == 1) {
                MaxOnes++;
            } else {
                MaxOnes = 0;                
            }
            MaxConOnes = max(MaxOnes, MaxConOnes);
        }
        
        return MaxConOnes;
    }
};