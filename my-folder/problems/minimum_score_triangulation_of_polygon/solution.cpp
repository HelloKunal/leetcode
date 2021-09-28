class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int nSides = values.size();
        vector<vector<int>> dpArray(nSides, vector<int>(nSides));
        
        for(int g = 0; g < nSides; g++) {
            
            for(int i = 0, j = g; j < nSides; i++, j++) {
                if(g == 0) dpArray[i][j] = 0;
                else if(g == 1) dpArray[i][j] = 0;
                else if(g == 2) dpArray[i][j] = values[i] * values[i+1] * values[i+2];
                else {
                    int minV = INT_MAX;
                    
                    for(int k = i+1; k < j; k++) {
                        int triV = values[i] * values[j] * values[k];
                        int leftV = dpArray[i][k];
                        int rightV = dpArray[k][j];
                        
                        minV = min(minV, triV+leftV+rightV);
                    }
                    
                    dpArray[i][j] = minV;
                }
            }
        }
        
        return dpArray[0][nSides-1];
    }
};