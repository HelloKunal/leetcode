/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    void dfs(pair<int, vector<int>> adj[], int* sum, vector<bool> &vis, int i) {
        *sum += adj[i].first;
        vis[i] = true;
        for(auto j : adj[i].second) {
            if(!vis[j]) {
                dfs(adj, sum, vis, j);
            }
        }
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        int size = 2001;
        pair<int, vector<int>> adj[size];
        for(auto i : employees) {
            adj[i->id].first = i->importance;
            for(auto j : i->subordinates) {
                adj[i->id].second.push_back(j);
            }
        }
        
        int sum = 0;
        vector<bool> vis(size, false);
        dfs(adj, &sum, vis, id);
        return sum;
    }
};