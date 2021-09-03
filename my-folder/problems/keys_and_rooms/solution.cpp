class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int i, vector<bool> &vis) {
        vis[i] = true;
        for(int j : rooms[i]) {
            if(!vis[j]) dfs(rooms, j, vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        dfs(rooms, 0, vis);
        for(bool i : vis) if(i == false) return false;
        return true;
    }
};