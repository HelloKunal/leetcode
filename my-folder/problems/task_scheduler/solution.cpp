class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> um;
        for (char c : tasks)
        {
            if (um.find(c) == um.end())
                um[c] = 1;
            else
                um[c]++;
        }
        
        priority_queue<int> maxHeap;
        for (auto t : um)
            maxHeap.push(t.second);
        
        int cycles = 0;
        while (!maxHeap.empty())
        {
            list <int> ls;
            for (int i = 0; i < n + 1; i++)
            {
                if (!maxHeap.empty())
                {
                    ls.push_back(maxHeap.top());
                    maxHeap.pop();
                }
            }
            
            for (int i : ls)
            {
                if (--i > 0)
                {
                    maxHeap.push(i);
                }
            }
            
            cycles += maxHeap.empty() ? ls.size() : n+1;
        }
        
        return cycles;
    }
};