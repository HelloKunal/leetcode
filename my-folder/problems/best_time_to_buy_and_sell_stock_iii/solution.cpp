class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int T_i01 = 0, T_i11 = INT_MIN;
        int T_j01 = 0, T_j11 = INT_MIN;
        for(int price : prices) {
            T_j01 = max(T_j01, T_j11 + price);
            T_j11 = max(T_j11, T_i01 - price);
            T_i01 = max(T_i01, T_i11 + price);
            T_i11 = max(T_i11, -price);
        }
        
        return T_j01;
    }
};