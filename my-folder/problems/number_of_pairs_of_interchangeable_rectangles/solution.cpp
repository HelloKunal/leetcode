class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, long long> rects;
        int size_r = rectangles.size();
        for(vector<int> rectangle : rectangles) {
            rects[1.0*rectangle[0]/rectangle[1]]++;
        }
        
        long long int res = 0;
        for(auto rect : rects) {
            if(rect.second > 1) {
                res += (rect.second-1)*(rect.second)/2;
            }
        }
        return res;
    }
};