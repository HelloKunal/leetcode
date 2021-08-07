class Solution {
public:
    int dr[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    
    bool checkBoundries (int nextr, int nextc)
    {
        if (nextr < 0 || nextr >= 8 || nextc < 0 || nextc >= 8)
            return false;
        
        return true;
    }
    
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        char oppositeColor = (color == 'W') ? 'B' : 'W';
        
        for (int i = 0; i < 8; i++)
        {
            int nextr = rMove + dr[i];
            int nextc = cMove + dc[i];
            
            if (checkBoundries (nextr, nextc))
                if (board[nextr][nextc] == oppositeColor)
                {
                    while (board[nextr][nextc] == oppositeColor)
                    {
                        nextr += dr[i];
                        nextc += dc[i];      
                        if (!checkBoundries (nextr, nextc)) 
                            break;
                    }

                    if (checkBoundries (nextr, nextc))
                        if (board[nextr][nextc] == color)
                            return true;
                }
        }
        
        return false;        
    }
};