class Solution {
public:
    void dfs(int curr, vector<bool> &vis, vector<vector<int>>& isConnected) {
        vis[curr] = true;
        for(int des = 0; des < isConnected.size(); des++) {
            if(vis[des] || curr==des || !isConnected[curr][des]) continue;
            dfs(des, vis, isConnected);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int nCities = isConnected.size();
        int res = 0;
        vector<bool> vis(nCities, false);
        for(int i = 0; i < nCities; i++) {
            if(vis[i]) continue;
            dfs(i, vis, isConnected);
            res++;
        }
        
        return res;
    }
};