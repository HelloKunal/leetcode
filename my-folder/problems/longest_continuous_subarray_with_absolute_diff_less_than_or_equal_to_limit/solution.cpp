class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int numsSize = nums.size();
        int res = 0;
        
        multiset<int> m;
        int i = 0, j = 0;
        for (i = 0; i < numsSize; i++)
        {
            m.insert(nums[i]);
            
            while ( *m.rbegin() - *m.begin() > limit)
            {
                m.erase (m.find(nums[j]));
                j++;
            }
            
            res = max (res, i-j+1);
        }
        
        return res;
    }
};