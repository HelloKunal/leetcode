class Solution {
public:
    int beauRec(vector<vector<vector<int>>> &memo, vector<int> &prices, int k, int i, bool bought) {
        if(i >= prices.size() || k == 0) return 0;
        if(memo[i][k][bought] != -1) {
            return memo[i][k][bought];
        }
        int res = beauRec(memo, prices, k, i+1, bought);
        if(bought) {
            res = max(res, beauRec(memo, prices, k-1, i+1, false) + prices[i]);
        } else {
            res = max(res, beauRec(memo, prices, k, i+1, true) - prices[i]);
        }
        
        return memo[i][k][bought] = res;
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> memo(prices.size(), vector<vector<int>>(k+1, vector<int> (2, -1)));
        return beauRec(memo, prices, k, 0, false);
    }
};