class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        sort(items.begin(), items.end());
        vector<int> subSumBea(n);
        vector<int> posArr(n);
        int maxBea = 0;
        for(int i = 0; i < n; i++) {
            posArr[i] = items[i][0];
            maxBea = max(maxBea, items[i][1]);
            subSumBea[i] = maxBea;
        }
        
        for(int &q : queries) {
            if(posArr[0] > q) q = 0;
            else q = subSumBea[(int) (upper_bound(posArr.begin(), posArr.end(), q) - posArr.begin() - 1)];
        }
        
        return queries;
    }
};