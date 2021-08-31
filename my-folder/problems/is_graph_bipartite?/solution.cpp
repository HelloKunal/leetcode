class Pair {
    public:
    int v;
    string psf;
    int level;
    
    Pair(int v, string psf, int level){
        this->v = v;
        this->psf = psf;
        this->level = level;
    }
};

class Solution {
public:
    bool checkSectionBipartite(vector<vector<int>>& graph, vector<int> &vis, int src) {
        queue<Pair> q;
        q.push(Pair(src, to_string(src), 0));
        
        while(!q.empty()) {
            auto pair = q.front();
            q.pop();
            
            if(vis[pair.v] != -1) {
                if(vis[pair.v] != pair.level) return false;
                
            } else {
                vis[pair.v] = pair.level;
            }
            
            for(int des : graph[pair.v]) {
                if(vis[des] == -1) {
                    q.push(Pair(des, pair.psf+to_string(des), pair.level+1));
                }
            }            
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V, -1);
        
        for(int i = 0; i < V; i++) {
            if(vis[i] == -1) {
                bool isSectionBipartite = checkSectionBipartite(graph, vis, i);
                if(!isSectionBipartite) return false;
            }
        }
        return true;
    }
};