class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for(int i = 0; i < n; i++) {
            if(manager[i] == -1) continue;
            adj[manager[i]].push_back(i);
        }
        
        queue<pair<int, int>> q;
        q.push(make_pair(headID, 0));
        int res = 0;
        while(!q.empty()) {
            auto idTime = q.front();
            q.pop();
            
            int time = idTime.second + informTime[idTime.first];
            res = max(res, time);
            for(int i : adj[idTime.first]) {
                q.push(make_pair(i, time));
            }
        }
        
        return res;
    }
};