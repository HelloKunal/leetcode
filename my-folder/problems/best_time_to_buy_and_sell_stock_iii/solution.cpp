class Solution {
public:
    vector<vector<vector<int>>> mem;
    int rec (vector<int> &prices, int pos, int trans, bool bought)
    {
        if (pos >= prices.size() || trans == 0)
            return 0;
        if (mem[bought][trans][pos] != -1)
            return mem[bought][trans][pos];
        
        int result = rec (prices, pos + 1, trans, bought); // SKIP
        if (bought)
        {
            result = max(result, rec (prices, pos + 1, trans-1, false) + prices[pos]);
        }
        else
        {
            result = max(result, rec (prices, pos + 1, trans, true) - prices[pos]);            
        }
        
        mem[bought][trans][pos] = result;
        return result;
    }
    int maxProfit(vector<int>& prices) {
         // rec and mem      
        mem.resize (2, vector<vector<int>> (3, vector<int> (prices.size(), -1)));
        int res = rec (prices, 0, 2, false);
        return res;
    }
};