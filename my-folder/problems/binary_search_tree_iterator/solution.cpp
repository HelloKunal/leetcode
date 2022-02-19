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
    stack<TreeNode*> st;
    
    BSTIterator(TreeNode* root) {
        add_left(root);    
    }
    
    void add_left(TreeNode* root) {
        while(root != NULL) {
            st.push(root);
            root = root->left;
        }
    }
    
    int next() {
        auto temp = st.top(); st.pop();
        
        if(temp->right != NULL) add_left(temp->right);
        
        return temp->val;
    }
    
    bool hasNext() {
        if(st.size() == 0) return false;
        else return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */