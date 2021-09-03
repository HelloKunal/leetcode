class Solution {
public:
    bool graphColoring(int n, vector<int> adj[], int i, vector<int> &colors) {
        queue<int> q;
        colors[i] = 0;
        q.push(i);
        
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for(int des : adj[curr]) {                
                if(colors[des] == colors[curr]) return false;
                if(colors[des] == -1) {
                    colors[des] = 1-colors[curr];
                    q.push(des);
                }
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n];
        for(auto i : dislikes) {
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);
        }
        
        vector<int> colors(n, -1);
        for(int i = 0; i < n; i++) {
            if(colors[i] == -1) if(!graphColoring(n, adj, i, colors)) return false;
        }
        return true;
    }
};