class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int sizeOfNum = num.size();
        
        stack <char> st;
        
        for (int i = 0; i < sizeOfNum; i++)
        {
            char charAtI = num[i];
            
            while ( st.size() > 0 && charAtI < st.top() && k > 0)
            {
                st.pop();
                k--;
            }
            
            st.push(charAtI);
        }
        
        while (k > 0)
        {
            st.pop(); // since k < sizeOfNum always
            k--;
        }
        
        int stSize = st.size();
        if (stSize == 0)
            return "0";
        char charRes[stSize];
        for (int i = stSize - 1; i >= 0; i--)
        {
            charRes[i] = st.top();
            st.pop();
        }
        
        int leadingZeros = 0;
        while (leadingZeros < stSize && charRes[leadingZeros] == '0')
        {
            leadingZeros++;
        }
        
        string res = "";
        for (int i = leadingZeros, y = stSize; i < y; i++)
        {
            res += charRes[i];
        }
        
        return res == "" ? "0" : res;
    }
};