class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        
        for(char c : num) {
            
            while(st.size() > 0 &&  c < st.top() && k > 0) {
                k--;
                st.pop();
            }
            
            st.push(c);
        }
        
        while(k > 0) {
            st.pop();
            k--;
        }
        
        // convert to string arr
        int stackSize = st.size();
        if(stackSize == 0) return "0";        
        vector<char> fullString(stackSize);
        for (int i = stackSize-1; i >= 0; i--) {
            fullString[i] = st.top();
            st.pop();
        }
        
        // remove leading zeros
        int leadingZeros = 0;
        while(leadingZeros < stackSize && fullString[leadingZeros] == '0') {
            leadingZeros++;
        }
        
        string res = "";
        for(int i = leadingZeros; i < stackSize; i++) {
            res += fullString[i];
        }
        
        return res == "" ? "0" : res;
    }
};