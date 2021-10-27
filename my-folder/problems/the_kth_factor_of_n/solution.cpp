class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors;
        for(int i = 1; i <= pow(n, 0.5); i++) {
            
            if(n % i == 0) {
                
                if(n / i == i) factors.push_back(i);
                else {
                    factors.push_back(i);
                    factors.push_back(n/i);
                }
            }
        }
        
        sort(factors.begin(), factors.end());
        return factors.size() < k ? -1 : factors[k-1];
    }
};