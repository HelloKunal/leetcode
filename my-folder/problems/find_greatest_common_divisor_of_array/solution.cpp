class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min = 1001, max = 0;
        for (int i : nums)
        {
            if (i < min)
                min = i;
            if (i > max)
                max = i;
        }
        
        return __gcd(max,min);        
    }
};