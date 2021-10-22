class Solution {
public:
    void NQRec(int curr, int n, vector<bool>& col, vector<bool>& Ldiag, vector<bool>& Rdiag, vector<string>& oneAns, vector<vector<string>>& ret) {
        if(curr == n) {
            ret.push_back(oneAns);
            return;
        }

        string thisRow = "";
        for(int i = 0; i < n; i++) {
            if(!col[i] && !Ldiag[i+curr] && !Rdiag[curr-i+n-1]) {
                string tempRow = thisRow + "Q";
                for(int j = tempRow.size(); j < n; j++) tempRow += ".";
                oneAns.push_back(tempRow);

                col[i] = true;
                Ldiag[i+curr] = true;
                Rdiag[curr-i+n-1] = true;
                NQRec(curr+1, n, col, Ldiag, Rdiag, oneAns, ret);
                col[i] = false;
                Ldiag[i+curr] = false;
                Rdiag[curr-i+n-1] = false;

                oneAns.pop_back();
            }
            thisRow += ".";
        }
    }
        
    vector<vector<string>> solveNQueens(int n) {
        if(n == 1) return {{"Q"}};
        vector<bool> col(n, false);
        vector<bool> Ldiag(2*(n-1), false);
        vector<bool> Rdiag(2*(n-1), false);

        vector<vector<string>> ret;
        vector<string> oneAns;
        NQRec(0, n, col, Ldiag, Rdiag, oneAns, ret);
        return ret;
    }
};