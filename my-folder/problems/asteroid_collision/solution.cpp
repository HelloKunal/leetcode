class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;
        for(int i = 0; i < ast.size(); i++) {
            if(st.size() == 0 || ast[i] > 0) {
                st.push(ast[i]);
                continue;
            }
            if(ast[i] < 0) {
                while(st.size() && st.top() > 0 && st.top() < abs(ast[i])) st.pop();
                if(st.size() && st.top() > 0 && st.top() == abs(ast[i])) st.pop();
                else if(st.size() && st.top() > 0 && st.top() > abs(ast[i]));
                else st.push(ast[i]);
            }
        }
        
        vector<int> res;
        while(st.size()) {
            res.push_back(st.top());
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};