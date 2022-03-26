class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int T_i01 = 0, T_i11 = INT_MIN;
        
        for(int price : prices) {
            T_i01 = max(T_i01, T_i11 + price);
            T_i11 = max(T_i11, -price);
        }
        
        return T_i01;
    }
};