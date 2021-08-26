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
    int total = 0;
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)    return 0;
        unordered_map<int, int> um;
        um[0] = 1;
        
        findPathSum(root, targetSum, 0, um);
        
        return total;
    }
    
    void findPathSum(TreeNode* root, int targetSum, int currentSum, unordered_map<int, int> um) {
        if(root == NULL)    return;
        currentSum += root->val;
        
        total += um[currentSum-targetSum];
        
        um[currentSum]++;
        findPathSum(root->left, targetSum, currentSum, um);
        findPathSum(root->right, targetSum, currentSum, um);
        um[currentSum]--;
    }
};