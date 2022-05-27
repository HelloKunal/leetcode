class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inorderSize(numCourses, 0);
        vector<int> adj[numCourses];
        for(auto i : prerequisites) {
            inorderSize[i[0]]++;
            adj[i[1]].push_back(i[0]);
        }
        
        queue<int> freeNodes;
        for(int i = 0; i < numCourses; i++) {
            if(inorderSize[i] == 0) {
                freeNodes.push(i);
            }
        }
        
        vector<int> res;
        while(freeNodes.size()) {
            int curr = freeNodes.front();
            freeNodes.pop();
            
            res.push_back(curr);
            
            for(int v : adj[curr]) {
                if(--inorderSize[v] == 0) {
                    freeNodes.push(v);
                }
            }            
        }
        
        if(res.size() != numCourses) return {};
        return res;
    }
};