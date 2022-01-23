class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int posIter = 0, negIter = 1;
        for(int i : nums) {
            if(i > 0) {
                res[posIter] = i;
                posIter += 2;
            } else {
                res[negIter] = i;
                negIter += 2;
            }
        }
            
        return res;
    }
};