class Solution {
public:
    vector<vector<int>> dpArr;
    int minDistUtil(string word1, string word2, int i, int j) {
        if(i == word1.length() && j == word2.length()) return 0;
        if(dpArr[i][j] != -1) return dpArr[i][j];
        else if(i == word1.length()) {
            return dpArr[i][j] = 1 + minDistUtil(word1, word2, i, j+1);
        } else if(j == word2.length()) {
            return dpArr[i][j] = 1 + minDistUtil(word1, word2, i+1, j);
        } else {
            if(word1[i] != word2[j]) return dpArr[i][j] = 1 + min(minDistUtil(word1, word2, i+1, j+1), min(minDistUtil(word1, word2, i+1, j), minDistUtil(word1, word2, i, j+1)));
            else return dpArr[i][j] = minDistUtil(word1, word2, i+1, j+1);
        }
    }
    int minDistance(string word1, string word2) {
        dpArr.assign(word1.length()+1, vector<int> (word2.length()+1, -1));
        return minDistUtil(word1, word2, 0, 0);
    }
};