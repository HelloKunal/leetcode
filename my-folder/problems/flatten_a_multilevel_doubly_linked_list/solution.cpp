/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
   
    Node* flatten(Node* head) {
        if(!head) return NULL;
        
        Node *headCopy = head;    
        // dfs iter
        stack<Node*> st;
        st.push(head);
        
        Node *temp, *prevNode = NULL;
        while(!st.empty()) {
            temp = st.top();
            st.pop();
            
            if(prevNode) prevNode->next = temp;
            temp->prev = prevNode;
            prevNode = temp;
            
            if(temp->next) st.push(temp->next);
            if(temp->child) {
                st.push(temp->child);
                temp->child = NULL; // like cleaning
            }
        }
        
        return headCopy;
    }
};