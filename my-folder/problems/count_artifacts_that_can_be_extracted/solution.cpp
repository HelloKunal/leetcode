class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<int>> graph(n, vector<int> (n, 0));
        int size = artifacts.size();
        
        for(int i = 0; i < size; i++) {
            for(int j = artifacts[i][0]; j <= artifacts[i][2]; j++) {
                for(int k = artifacts[i][1]; k <= artifacts[i][3]; k++) {
                    graph[j][k] = i+1;
                }
            }
        }
        
        
        for(auto i : dig) {
            graph[i[0]][i[1]] = 0;
        }
        
        set<int> notRes;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(graph[i][j] != 0) notRes.insert(graph[i][j]);
            }
        }
        
        int res = size;
        res -= notRes.size();
        return res;
        // sort(notRes.begin(), notRes.end());
        // int res = 0;
        // for(int i = 1; i <= n; i++) {
        //     if(binary_search(notRes.begin(), notRes.end(), i) == false) res++;
        // }
    }
};