/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode* curr = root;
        
        while (true)
        {
            while (curr)
            {
                st.push(curr);
                st.push(curr);
                curr = curr -> left;
            }
            
            if (st.empty())
                break;
            curr = st.top();
            st.pop();
            
            if (!st.empty() && curr == st.top())
                curr = curr -> right;
            else
            {                
                ans.push_back(curr->val);
                curr = NULL;
            }
            
        }
        
        return ans;
    }
};