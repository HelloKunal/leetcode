class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, long> c;
        for(int i : arr) {
            c[i]++;
        }
        
        long int count = 0;
        for(auto it: c) {
            for(auto it2 : c) {
                int i = it.first, j = it2.first, k = target - i - j;
                if(!c.count(k)) continue;
                
                if(i == j && j == k) {
                    count += (c[i] * (c[i]-1) * (c[i]-2)) / 6;
                } else if(i == j && j != k) {
                    count += (c[i] * (c[i]-1) / 2) * c[k];
                } else if(i < j && j < k) {
                    count += c[i] * c[j] * c[k];
                    
                }
            }
        }
        
        return count % int (1e9 + 7);
    }
};