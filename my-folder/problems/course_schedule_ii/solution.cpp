class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inorderCol(numCourses, 0);
        vector<int> adj[numCourses];
        for(auto p : prerequisites) {
            inorderCol[p[0]]++;
            adj[p[1]].push_back(p[0]);
        }
        
        queue<int> freeNodes;
        for(int i = 0; i < numCourses; i++) {
            if(inorderCol[i] == 0) freeNodes.push(i);
        }
        
        vector<int> res;
        while(freeNodes.size() > 0) {
            int freeNode = freeNodes.front();
            freeNodes.pop();
            res.push_back(freeNode);
            
            for(int v : adj[freeNode]) {
                if(--inorderCol[v] == 0) {
                    freeNodes.push(v);
                }
            }
        }
        
        if(res.size() != numCourses) return {};
        else return res;
    }
};