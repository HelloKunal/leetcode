class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int uSize = graph.size();
        
        vector<int> vis(uSize, -1);
        for(int i = 0; i < uSize; i++) {
            if(vis[i] == -1) {
                if(!isComponentBipartite(graph, i, vis)) return false;
            }
        }
        
        return true;
    }
    
    bool isComponentBipartite(vector<vector<int>>& adj, int firstVertex, vector<int>& vis) {
        queue<pair<int, int>> q;
        q.push({firstVertex, 0});
        
        while(q.size() > 0) {  
            auto item = q.front(); q.pop();
            int currVertex = item.first;
            int currLevel = item.second;
            
            if(vis[currVertex] == -1) {
                vis[currVertex] = currLevel;
            } else {
                if(currLevel != vis[currVertex]) return false;
            }
            
            for(int i : adj[currVertex]) {
                if(vis[i] == -1) {
                    q.push({i, currLevel+1});
                }
            }
        }
        
        return true;
    }
};