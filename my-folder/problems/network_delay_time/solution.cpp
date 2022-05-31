class Solution {
public:
    
    void dfs(vector<pair<int, int>> adj[], int curr, int time, vector<int>& vis) {
        vis[curr] = min(vis[curr], time);
        
        for(auto item : adj[curr]) {
            if(vis[item.first] > (time + item.second)) {
                dfs(adj, item.first, time + item.second, vis);        
            }
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int ,int>> adj[n];
        for(auto item : times) {
            adj[item[0]-1].push_back({item[1]-1, item[2]});
        }
        
        vector<int> vis(n, INT_MAX);
        
        dfs(adj, k-1, 0, vis);
        int maxTime = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i] == INT_MAX) return -1;
            maxTime = max(maxTime, vis[i]);
        }
        
        return maxTime;
    }
};