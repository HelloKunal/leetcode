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
    
    vector<int> ans;
    void inorder (TreeNode* root)
    {
        stack<TreeNode*> st;
        if (root == NULL)
            return;
        TreeNode* curr = root;
        while (!st.empty() || curr != NULL)
        {
            while (curr)
            {
                st.push(curr);
                curr = curr ->left;
            }
            
            curr = st.top();
            st.pop();
            ans.push_back(curr->val);
            
            curr = curr->right;
        }
        
    }

    bool isValidBST(TreeNode* root) {
        
        ans = {};
        inorder (root);
        for (int i = ans.size() - 1; i > 0; i--)
        {
            if (ans[i] <= ans[i - 1])
                return false;
        }
        return true;
        
        
    }
};