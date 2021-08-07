/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == NULL)
            return {};
        
        vector<vector<int>> ans;
        unordered_map<int, bool> vis;
        
        queue<Node*> st;
        st.push(root);
        while (!st.empty())
        {
            int size = st.size();
            vector<int> temp;
            
            for (int i = 0; i < size; i++)
            {
                Node* curr = st.front();
                temp.push_back(curr->val);
                st.pop();

                for (Node* child : curr->children)
                {
                    if (child != NULL)
                        st.push(child);
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};