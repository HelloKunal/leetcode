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
class BSTIterator {
public:
    list<int> q;
    void inorder (TreeNode* root)
    {
        if (!root)
            return;
        inorder(root->left);
        q.push_back(root->val);
        inorder(root->right);
    }
    BSTIterator(TreeNode* root) {
        q = {};
        q.push_back(INT_MIN);
        inorder(root);
    }
    
    int next() {
        q.pop_front();
        return q.front();
    }
    
    bool hasNext() {
        if (q.size() == 1)
            return false;
        return true;
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */