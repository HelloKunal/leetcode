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
    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL)
            return -1;
        int count = 0;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while (curr != NULL || !st.empty())
        {
            while (curr)
            {
                st.push(curr);
                curr = curr -> left;
            }
            
            curr = st.top();
            st.pop();
            count++;
            if (count == k)
                break;
            
            curr = curr -> right;
        }
        
        return curr->val;
    }
};