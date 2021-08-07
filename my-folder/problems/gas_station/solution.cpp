class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        
        int start = 0, balance = 0;
        for (int i = 0; i < n*2; i++)
        {
            balance += gas[i%n] - cost[i%n];
            if (balance < 0)
            {
                balance = 0;
                start = i + 1;
            }
        }
        if (start >= n)
            return -1;
        return start % n;
    }
};