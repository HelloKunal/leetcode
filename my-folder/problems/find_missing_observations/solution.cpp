class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int Am = 0;
        for(int roll : rolls) Am += roll;
        int An = mean*(n+m) - Am;
        
        vector<int> rollsA(n, 1);
        if(An < n || An > 6*n) return {};
        An -= n;
        
        for(int i = 0; i < n; i++) {
            for(int j = 5; j >= 0; j--) {
                if(An - j >= 0 && rollsA[i]+j <= 6) {
                    rollsA[i] += j;
                    An -= j;
                }
                if(rollsA[i] == 6) break;
                if(An == 0) return rollsA;
            }
        }
        
        return rollsA;
    }
};