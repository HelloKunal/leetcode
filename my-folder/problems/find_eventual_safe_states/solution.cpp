class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int i, vector<bool> &vis, vector<int> &memo) {
        if(memo[i] != -1) {
            return bool(memo[i]);
        }
        vis[i] = true;
        if(graph[i].size() == 0) {
            vis[i] = false;
            memo[i] = true;
            return true;
        }
        
        bool isNextNodeSafe;
        for(int j = 0; j < graph[i].size(); j++) {
            if(vis[graph[i][j]] == true) {
                vis[i] = false;
                memo[i] = false;
                return false;
            }
            isNextNodeSafe = dfs(graph, graph[i][j], vis, memo);
            if(isNextNodeSafe == false){                
                vis[i] = false;
                memo[i] = false;
                return false;
            }
        }
        vis[i] = false;
        memo[i] = true;
        return true;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> res;
        vector<bool> vis;
        vector<int> memo(n, -1);
        for(int i = 0; i < n; i++) {
            vis.assign(n, false);
            bool isNodeSafe = dfs(graph, i, vis, memo);
            if(isNodeSafe) res.push_back(i);
        }
        
        return res;
    }
};