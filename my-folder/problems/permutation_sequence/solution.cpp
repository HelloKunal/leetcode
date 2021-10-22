class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> givenSet;
        vector<int> fact(n);
        int f = 1;
        for(int i = 1; i < n; i++) {
            f *= i;
            fact[i] = f;
        }
        for(int i = 1; i <= n; i++) givenSet.push_back(i);

        
        string ret = "";
        while(1) {
            if(n == 1) {
                ret += to_string(givenSet.back());
                break;
            }
            
            int block = k / fact[n-1];
            if(k % fact[n-1] == 0) block -= 1;
            
            ret += to_string(givenSet[block]);
            givenSet.erase(givenSet.begin() + block);
            
            k -= fact[n-1]*block;
            n--;
        }
        
        return ret;
    }
};