class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int T_100 = 0, T_101 = INT_MAX;
        for(int price : prices) {
            T_100 = max(T_100, price - T_101);
            T_101 = min(T_101, price);
        }
        
        return T_100;
    }
};