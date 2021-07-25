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
    vector<int> vt;
    void inorder (TreeNode* root)
    {
        if (root == NULL)
            return;
        
        inorder(root->left);
        vt.push_back(root->val);
        inorder(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        vt = {};
        inorder (root);
        return twopointer(k);
    }
    bool twopointer(int k)
    {
        for (int i = 0, j = vt.size() - 1; i < j;)
        {
            if (vt[i] + vt[j] == k)
                return true;
            else if (vt[i] + vt[j] < k)
                i++;
            else
                j--;
        }
        return false;
    }
};