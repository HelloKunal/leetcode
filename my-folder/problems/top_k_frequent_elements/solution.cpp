class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        for(int num : nums)
        {
            um[num]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (auto i : um)
        {
            minHeap.push(make_pair(i.second, i.first));
            
            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }
        
        vector<int> res;
        while(minHeap.size() > 0)
        {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return res;
    }
};