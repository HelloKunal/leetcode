class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int numPiles = stones.size();
        if((numPiles-1) % (k-1) != 0) return -1;
        vector<vector<int>> dpArray(numPiles, vector<int>(numPiles, 0));
        vector<int> prefixSArray(numPiles+1);
        prefixSArray[0] = 0;
        for(int i = 0; i < numPiles; i++) prefixSArray[i+1] = stones[i] + prefixSArray[i];
        
        for(int g = 0; g < numPiles; g++) {
            
            for(int i = 0, j = g; j < numPiles; i++, j++) {
                if(g < k-1) continue;
                else if(g == k-1) dpArray[i][j] = prefixSArray[j+1] - prefixSArray[i];
                else {
                    int min_temp = INT_MAX;
                    for(int x = i; x < j; x+=k-1) {
                        min_temp = min(min_temp, dpArray[i][x] + dpArray[x+1][j]);
                    }
                    if(g % (k-1) == 0) min_temp += prefixSArray[j+1] - prefixSArray[i];
                    
                    dpArray[i][j] = min_temp;
                }
            }
        }
        
        return dpArray[0][numPiles-1];
    }
};