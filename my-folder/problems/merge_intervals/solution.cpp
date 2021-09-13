class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        // return intervals;
        vector<vector<int>> res;
        for(int i = 0; i < intervals.size(); i++) {
            vector<int> temp = intervals[i];
            while(i < intervals.size()-1 && temp[1] >= intervals[i+1][0]) {
                temp[1] = max(temp[1], intervals[i+1][1]);
                i++;
            }
            res.push_back(temp);
        }
        
        return res;
    }
};