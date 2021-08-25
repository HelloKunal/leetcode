class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int xAxis = matrix[0].size();
        int yAxis = matrix.size();
        
        // every row is now a prefix
        for(int i = 0; i < yAxis; i++) {
            for(int j = 1; j < xAxis; j++) {
                matrix[i][j] += matrix[i][j-1];
            }
        }
        
        int ans = 0;
        unordered_map<int, int> um;
        for(int j = 0; j < xAxis; j++) {
            for(int k = j; k < xAxis; k++) {
                int sum = 0;
                um.clear();
                um[0] = 1; // edge case
                for(int i = 0; i < yAxis; i++) {
                    sum += matrix[i][k] - (j ? matrix[i][j-1] : 0);
                    if(um.find(sum-target) != um.end())  ans += um[sum-target];
                    um[sum]++;
                }
            }
        }
        
        return ans;
    }
};