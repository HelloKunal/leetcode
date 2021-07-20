class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0, y = s.size(); i < y / 2; i++)
        {
            swap(s[i], s[y - i - 1]);
        }
    }
};