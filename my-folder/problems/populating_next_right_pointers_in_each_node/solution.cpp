/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void connectUtil(Node* lNode, Node* rNode) {
        if(lNode == NULL) return;
        lNode->next = rNode;
        connectUtil(lNode->left, lNode->right);
        if(rNode == NULL) {
            // connectUtil(lNode->right, NULL);
            return;
        }
        connectUtil(lNode->right, rNode->left);
        connectUtil(rNode->left, rNode->right);
        // connectUtil(rNode->right, NULL);
    }
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        connectUtil(root->left, root->right);
        return root;
    }
};