class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int, vector<int>>> maxHeap;
        
        for(vector<int> point : points)
        {
            int dist = pow(point[1], 2)+pow(point[0], 2);
            maxHeap.push(make_pair(dist, point));
            
            if (maxHeap.size() > k)
                maxHeap.pop();
        }
        
        while(maxHeap.size() > 0)
        {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return res;
    }
};