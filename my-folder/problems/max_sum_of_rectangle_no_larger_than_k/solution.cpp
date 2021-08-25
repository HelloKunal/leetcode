class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int xAxis = matrix[0].size();
        int yAxis = matrix.size();
        
        for(int i = 0; i < yAxis; i++) {
            for(int j = 1; j < xAxis; j++) {
                matrix[i][j] += matrix[i][j-1];
            }
        }
        
        set<int> us;
        int ans = INT_MIN;
        for(int left = 0; left < xAxis; left++) {
            for(int right = left; right < xAxis; right++) {
                int sum = 0;
                us.clear();
                us.insert(0);
                for(int height = 0; height < yAxis; height++) {
                    sum += matrix[height][right];
                    if(left > 0)
                        sum -= matrix[height][left-1];
                    
                    auto itr = us.lower_bound(sum-k);
                    if(itr != us.end()) {
                        ans = max(ans, sum-(*itr));
                    }                    
                    us.insert(sum);
                }
            }
        }
        
        return ans;
    }
};