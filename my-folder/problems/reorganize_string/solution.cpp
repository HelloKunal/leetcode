class Solution {
public:
    string reorganizeString(string s) {
        if(s.length() == 1) return s;
        
        vector<int> charFreqArr(26, 0);
        priority_queue<pair<int, char>> maxHeap;
        for(char c : s) charFreqArr[c - 'a']++;
        for(int i = 0; i <= 25;  i++) {
            if(charFreqArr[i]) {
                maxHeap.push({charFreqArr[i], (char)(i+'a')});
            }
        }
        
        string res = "";
        while(maxHeap.size() >= 2) {
            auto a = maxHeap.top(); maxHeap.pop();
            auto b = maxHeap.top(); maxHeap.pop();
            res += a.second;
            res += b.second;
            if(--a.first) maxHeap.push(a);
            if(--b.first) maxHeap.push(b);
        }
        
        if(maxHeap.size() == 1) {
            auto a = maxHeap.top();
            if(a.first >= 2) return "";
            else res += a.second;
        }
        
        return res;
    }
};