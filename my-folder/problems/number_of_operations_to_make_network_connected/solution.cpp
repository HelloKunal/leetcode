class Solution {
public:
    void dfs (int i, vector<vector<int>> &adj, vector<bool>& vis)
    {
        vis[i] = true;
        
        for (int j : adj[i])
        {
            if (!vis[j])
                dfs (j, adj, vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;
        
        vector<vector<int>> adj(n);
        for (auto v : connections)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<bool> vis (n, false);
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {    
                dfs (i, adj, vis);
                count++;
            }
        }
        return count - 1;
    }
private:
};