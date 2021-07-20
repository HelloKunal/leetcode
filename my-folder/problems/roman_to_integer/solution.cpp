class Solution {
public:
    int romanToInt(string s) {
        unordered_map <char, int> ch = {{'I', 1},
                                        {'V', 5},
                                        {'X', 10},
                                        {'L', 50},
                                        {'C', 100},
                                        {'D', 500},
                                        {'M', 1000}};
        
        int sum = ch[s.back()];
        for (int i = s.size() - 2; i >= 0; i--)
        {
            if (ch[s[i]] < ch[s[i + 1]])
                sum -= ch[s[i]];
            else
                sum += ch[s[i]];
        }
        
        return sum;
    }
};