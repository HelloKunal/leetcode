class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();      
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {              
                    q.push(make_pair(i+1, j));         
                    q.push(make_pair(i-1, j));         
                    q.push(make_pair(i, j+1));         
                    q.push(make_pair(i, j-1));            
                    
                }
            }
        }
        
        int steps = 0;
        while(!q.empty()) {
            steps++;
            int s = q.size();
            for(int x = 0; x < s; x++) {
                auto xy = q.front();
                q.pop();
                int i = xy.first;
                int j = xy.second;
                if(i >= 0 && i < n && j >= 0 && j < n && grid[i][j] == 0){
                    grid[i][j] = steps;                            
                    q.push(make_pair(i+1, j));         
                    q.push(make_pair(i-1, j));         
                    q.push(make_pair(i, j+1));         
                    q.push(make_pair(i, j-1));   
                }
            }
        }
        return steps == 1 ? -1 : steps-1;
    }
};