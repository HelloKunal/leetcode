class Solution {
public:
    int di[5] = {0, 1, 0, -1, 0};
    unordered_map<int, int> colorSize;
    int n;
    int largestIsland(vector<vector<int>>& grid) {
        colorSize = {};
        n = grid.size();
        int color = 2;
        int max_sum = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)    continue;
                paint (i, j, grid, color++);
                max_sum = max (max_sum, colorSize[color - 1]);
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                unordered_set<int> neighbours;
                if (grid[i][j] == 0)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int ni = i + di[k], nj = j + di[k + 1];
                        if (ni < 0 || nj < 0 || ni == n || nj == n)
                            continue;
                        neighbours.insert( grid[i + di[k]][j + di[k+1]]);
                    }
                    
                    int sum = 1;
                    for (int i : neighbours)
                    {
                        sum += colorSize[i];
                    }
                    
                    max_sum = max (sum, max_sum);
                }
                
            }
        }
        return max_sum;
    }
    
    void paint (int i, int j, vector<vector<int>>& grid, int color)
    {
        if (i < 0 || j < 0 || i == n || j == n || grid[i][j] != 1)
            return;
        grid[i][j] = color;
        colorSize [color] += 1;
        for (int k = 0; k < 4; k++) paint (i + di[k], j + di[k+1], grid, color);               
    }
};