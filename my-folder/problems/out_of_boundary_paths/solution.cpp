class Solution {
public:
    int dxy[5] = {0, 1, 0, -1, 0};
    int mod = pow(10, 9) + 7;
    map<tuple<int, int, int>, int> cache;
    int DFS(int m, int n, int maxMove, int i, int j) {
        if(i >= m || i < 0 || j < 0 || j >= n) return 1;
        if(maxMove == 0) return 0;
        
        auto find = cache.find({maxMove, i, j});
        if(find != cache.end()) return find->second;
        
        int res = 0;
        for(int k = 0; k < 4; k++) {
            int nx = i + dxy[k];
            int ny = j + dxy[k+1];
            res = (res + (DFS(m, n, maxMove-1, nx, ny) % mod)) % mod;
        }
        
        return cache[{maxMove, i, j}] = res;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if(maxMove == 0) return 0;
        
        return DFS(m, n, maxMove, startRow, startColumn);
    }
};