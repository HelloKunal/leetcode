class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> countAtMom(1001);
        for(auto trip : trips) {
            countAtMom[trip[1]] += trip[0];
            countAtMom[trip[2]] -= trip[0];
        }
        
        int count = 0;
        for(int i : countAtMom) {
            count += i;
            if(count > capacity) return false;
        }
        return true;
    }
};