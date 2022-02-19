class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> res;
        if(num < 3) {
            if(num == 0) {
                res.push_back(-1);
                res.push_back(0);
                res.push_back(+1);
            }
            return res;
        }
        
        if((num - 3) % 3 == 0) {
            long long int x = (num - 3) / 3;
            res.push_back(x);
            res.push_back(x+1);
            res.push_back(x+2);
        }
        
        return res;
    }
};