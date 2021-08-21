class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> um;
        for (char c : s)
        {
            um[c]++;
        }
        
        priority_queue<pair<int, char>> maxHeap;
        for (auto i : um)
        {
            maxHeap.push(make_pair(i.second, i.first));
        }
        
        string res = "";
        while(maxHeap.size() > 0)
        {
            for (int i = 0; i < maxHeap.top().first; i++)
                res += (maxHeap.top().second);
            maxHeap.pop();
        }
        
        return res;
    }
};