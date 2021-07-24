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
    bool isSymmetric (TreeNode* root)
    {
        if (!root)
            return false;
        
        stack<TreeNode*> leftstack;
        stack<TreeNode*> rightstack;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        while (left != NULL || right != NULL || !leftstack.empty() || !rightstack.empty())
        {
            if (left == NULL && right != NULL)
                return false;
            else if (left != NULL && right == NULL)
                return false;
            else if (left != NULL && right != NULL)
            {
                if (left->val != right->val)
                    return false;
                
                leftstack.push(left);
                rightstack.push(right);
                left = left->left;
                right = right->right;
            }
            else
            {
                left = leftstack.top()->right;
                right = rightstack.top()->left;
                leftstack.pop();
                rightstack.pop();
            }
        }
        return true;
    }
};