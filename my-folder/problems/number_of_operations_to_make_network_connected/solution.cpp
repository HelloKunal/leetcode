class Solution {
public:
    void dfs(vector<int> adj[], int i, vector<bool> &vis) {
        if(vis[i]) return;
        vis[i] = true;
        for(int j : adj[i]) {
            dfs(adj, j, vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        int E = 0;
        for(vector<int> &connection: connections) {
            E++;
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }
        
        vector<bool> vis(n, false);
        int conCom = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(adj, i, vis);
                conCom++;
            }
        }
        
        if(E < n-1) return -1;
        int redEdges = E - ((n-1) - (conCom-1));
        if(redEdges >= (conCom-1)) {
            return conCom-1;
        }
        return -1;
    }
};