class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int numsSize = nums.size();
        string s = "";
        for (int i = 0; i < numsSize; i++)
        {
            s += "1";  
        }
        for (int i = 0; i < numsSize; i++)
        {
            s += "0";  
        }
        
        while (find(nums.begin(), nums.end() , s.substr(0, numsSize)) != nums.end())
        {
            prev_permutation(s.begin(), s.end());
        }
        return s.substr(0,numsSize);
    }
};