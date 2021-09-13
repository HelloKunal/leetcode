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
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while(true) {
            // go left
            while(curr) {
                st.push(curr);
                st.push(curr);
                curr = curr->left;
            }
            
            // check stack
            if(st.empty()) break;
            curr = st.top();
            st.pop();
            
            // go right and print
            if(!st.empty() && curr == st.top()) {
                curr = curr->right;
            } else {
                res.push_back(curr->val);
                curr = NULL;
            }
        }
        
        return res;
    }
};