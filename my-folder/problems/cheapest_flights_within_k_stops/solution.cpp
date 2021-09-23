class Solution {
public:
    
    vector<vector<int>> memoArray;
    int findCheapestPriceUtil(vector<pair<int, int>> paths[], int dst, int k, int curr) {
        if(k < 0) return INT_MAX;
        if(curr == dst) {
            return 0;
        }
        if(memoArray[curr][k] != -1) return memoArray[curr][k];
        
        int cheapestPrice = INT_MAX;
        for(auto path : paths[curr]) {
            int a = findCheapestPriceUtil(paths, dst, k-1, path.first);
            if(a != INT_MAX) {
                cheapestPrice = min(cheapestPrice, a + path.second);
            } 
        }
        
        return memoArray[curr][k] = cheapestPrice;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> paths[n];
        for(vector<int> flight : flights) {
            paths[flight[0]].push_back({flight[1], flight[2]});
        }
        
        memoArray.assign(n, vector<int> (k+2, -1));
        
        int cheapestPrice = findCheapestPriceUtil(paths, dst, k+1, src);
        if(cheapestPrice == INT_MAX) return -1;
        else return cheapestPrice;
    }
};