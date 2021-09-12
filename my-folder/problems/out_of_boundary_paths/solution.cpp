class Solution {
public:
    vector<vector<vector<int>>> memo;
    int RecPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if(startRow > m-1 || startRow < 0 || startColumn > n-1 || startColumn < 0) return 1;
        if(maxMove == 0) return 0;
        if(memo[startRow][startColumn][maxMove] != -1) return memo[startRow][startColumn][maxMove];
        int top = RecPaths(m, n, maxMove-1, startRow+1, startColumn)%(1000000007);
        int right = RecPaths(m, n, maxMove-1, startRow, startColumn+1)%(1000000007);
        int bottom = RecPaths(m, n, maxMove-1, startRow-1, startColumn)%(1000000007);
        int left = RecPaths(m, n, maxMove-1, startRow, startColumn-1)%(1000000007);
        return memo[startRow][startColumn][maxMove] = ((top+right)%1000000007+(bottom+left)%1000000007)%1000000007;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memo.assign(m, vector<vector<int>> (n, vector<int> (maxMove+1, -1)));
        return RecPaths(m, n, maxMove, startRow, startColumn);
    }
};