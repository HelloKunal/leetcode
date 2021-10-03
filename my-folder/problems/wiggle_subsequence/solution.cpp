class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int upSeq = 1, downSeq = 1;
        int prev = nums[0];
        for(int num : nums) {
            if(num > prev) {
                upSeq = downSeq + 1;
            }
            if(num < prev) {
                downSeq = upSeq + 1;
            }
            prev = num;
        }
        
        return max(upSeq, downSeq);
    }
};