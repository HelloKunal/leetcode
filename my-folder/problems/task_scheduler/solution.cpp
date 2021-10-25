class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> um;
        for(char c : tasks) um[c]++;
        
        priority_queue<int> maxHeap;
        for(auto it : um) maxHeap.push(it.second);
        
        int res = 0;
        while(!maxHeap.empty()) {
            list<int> ls;
            
            for(int i = 0; i < n+1; i++) { // because we start counting after
                if(!maxHeap.empty()) {
                    ls.push_back(maxHeap.top()); maxHeap.pop();
                } else break;
            }
            
            for(int i : ls) {
                if(--i > 0) maxHeap.push(i);
            }
            
            res += maxHeap.empty() ? ls.size() : n+1;
        }
        
        return res;
    }
};