class Solution {
public:
    struct node {
        int data;
        int maximum;
    };
    
    void insert(stack<node> &st, int dat) {
        node elem;
        elem.data = dat;
        if(st.size() == 0) elem.maximum = dat;
        else {
            elem.maximum = max(dat, st.top().maximum);
        }
        st.push(elem);
        return;
    }
    
    void deleted(stack<node> &s1, stack<node> &s2) {
        if(s1.size()) s1.pop();
        else {
            while(s2.size()) {
                node temp = s2.top();
                insert(s1, temp.data);
                s2.pop();
            }
            s1.pop();
        }
    }
    
    int get_max(stack<node> &s1, stack<node> &s2) {
        int ans=INT_MIN;
        if(s1.size()) ans=max(ans,s1.top().maximum);
        if(s2.size()) ans=max(ans,s2.top().maximum);
        return ans;
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        stack<node> s1, s2;
        for(int i = 0; i < k-1; i++) insert(s2, nums[i]);
        
        vector<int> res;
        for(int i = 0; i <= nums.size()-k; i++) {
            if(i-1 >= 0) deleted(s1, s2);
            insert(s2, nums[i+k-1]);
            res.push_back(get_max(s1, s2));
        }
        
        return res;
    }
};