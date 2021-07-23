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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode* curr = root;
        st.push(curr);
        
        while (!st.empty())
        {         
            TreeNode* curr = st.top();
            st.pop();
            
            while (curr != NULL)
            {
                st.push(curr-> right);
                ans.push_back(curr->val);
                curr = curr -> left;
            }
        }
        return ans;
    }
};