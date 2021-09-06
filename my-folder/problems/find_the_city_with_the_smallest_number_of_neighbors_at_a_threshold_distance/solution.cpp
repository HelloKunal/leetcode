class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 10001));
        for(int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        for(vector<int> &e : edges) {
            dist[e[0]][e[1]] = dist[e[1]][e[0]] = e[2];
        }
        
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        int min_count = INT_MAX;
        int res = 0;
        for(int i = 0; i < n; i++) {
            
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            
            if(count <= min_count) {
                min_count = count;
                res = i;
            }
        }
        
        return res;
    }
};