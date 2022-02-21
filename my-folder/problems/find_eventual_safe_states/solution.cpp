class Solution {
public:    
    vector<bool> visArr;
    bool isCyclic = false;
    bool dfsUtil(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& currVisited, int i, vector<bool>& safe) {
        visited[i] = true;
        currVisited[i] = true;
        
        for(int j : graph[i]) {
            if(!visited[j]) {
                if(!dfsUtil(graph, visited, currVisited, j, safe)) {
                    return safe[i] = false;
                }                
            } else if(visited[j] && currVisited[j]) {
                return safe[i] = false;
            }
        }
        
        currVisited[i] = false;
        return safe[i];
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int vertices = graph.size();
        vector<bool> visited(vertices, false);
        vector<bool> currVisited(vertices, false);
        vector<bool> safe(vertices, true);
        
        for(int i = 0; i < vertices; i++) {
            if(!visited[i]) {
                dfsUtil(graph, visited, currVisited, i, safe);
            }
        }
        
        vector<int> res;
        for(int i = 0; i < vertices; i++) {
            if(safe[i]) res.push_back(i);
        }
        
        return res;
    }
};