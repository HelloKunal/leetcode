class Solution {
public:
    vector<vector<vector<int>>> mem;
    int rec (vector<int> &prices, int pos, int t, bool bought)
    {
        if (pos >= prices.size() || t == 0)
            return 0;
        if (mem[bought][t][pos] != -1)
            return mem[bought][t][pos];
        
        int result = rec (prices, pos + 1, t, bought); // skip
        if (bought)
        {
            result = max (result, rec (prices, pos + 1, t - 1, false) + prices[pos]);
        }
        else
        {
            result = max (result, rec (prices, pos + 1, t, true) - prices[pos]);
        }
        
        mem[bought][t][pos] = result;
        return result;
    }
    int maxProfit(int k, vector<int>& prices) {
        mem.resize (2, vector<vector<int>> (k+1, vector<int> (prices.size(), -1)));
        int res = rec (prices, 0, k, false);
        return res;
    }
};