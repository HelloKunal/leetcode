class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int T_ik0 = 0, T_ik1 = INT_MIN;
        int T_ik0old1 = 0, T_ik0_old2 = 0;
        
        for(int price : prices) {
            T_ik0old1 = T_ik0;
            T_ik0 = max(T_ik0, T_ik1 + price);
            T_ik1 = max(T_ik1, T_ik0_old2 - price);
            T_ik0_old2 = T_ik0old1;
        }
        
        return T_ik0;
    }
};