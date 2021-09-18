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
    long long int res = 0, totalSum = 0, sumThatweReturn;
    int sumOfUnderRootIncludding(TreeNode* root) {
        if(root == NULL) return 0;
        sumThatweReturn = root->val + sumOfUnderRootIncludding(root->left) + sumOfUnderRootIncludding(root->right);
        res = max(res, sumThatweReturn * (totalSum - sumThatweReturn));
        return sumThatweReturn;
    }
    int maxProduct(TreeNode* root) {
        totalSum = sumOfUnderRootIncludding(root);
        sumOfUnderRootIncludding(root); // Because we get res now
        return res % 1000000007;
    }
};