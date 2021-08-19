class Solution {
public:
    int atMostK (vector<int>& nums, int k)
    {
        int numSize = nums.size();
        int res = 0;
        
        int i = 0, j = 0;
        unordered_map<int, int> um;
        for (i = 0; i < numSize; i++)
        {
            if (um[nums[i]] == 0)
                k--;
            
            um[nums[i]]++;
            
            while (j < numSize && k < 0)
            {
                um[nums[j]]--;
                if (um[nums[j]] == 0)
                    k++;
                j++;
            }
            
            res += i - j + 1;
        }
        
        return res;
        
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k-1);
    }
};