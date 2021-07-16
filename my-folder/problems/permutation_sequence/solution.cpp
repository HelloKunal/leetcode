class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;
        for (int i = 1; i < n; i++)
        {
            fact *= i;
            numbers.push_back(i);
        }
        string ans = "";
        numbers.push_back(n);
        k -= 1;
        while (true)
        {
            ans += to_string (numbers[k/fact]);
            numbers.erase (numbers.begin() + k/fact);
            if (numbers.size() == 0)
                break;
            k %= fact;
            fact /= numbers.size();
        }
        
        return ans;
    }
};