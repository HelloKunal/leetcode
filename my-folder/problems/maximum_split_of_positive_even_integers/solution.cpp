class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        int n = 2;
        vector<long long> res;
        if(finalSum == 1 || finalSum % 2 != 0) return res;
        while(finalSum > 0) {
            finalSum -= n;
            res.push_back(n);
            n += 2;
        }
        
        if(finalSum < 0) {
            int pos = finalSum / 2;
            pos = -pos;
            res.erase(res.begin() + pos - 1);
        }
        
        return res;
    }
};