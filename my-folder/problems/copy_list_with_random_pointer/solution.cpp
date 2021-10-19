/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        
        Node* headCopy = head;
        while(head != NULL) {
            Node* temp = new Node(head->val), *temp2 = head->next;
            head->next = temp;
            temp->next = temp2;
            head = head->next; head = head->next;
        }
        
        head = headCopy;
        while(head != NULL) {
            if(head->random != NULL) {
                (head->next)->random = (head->random)->next;
            }
            head = head->next; head = head->next;
        }
        
        head = headCopy;
        Node *newHead = head->next;
        Node *newHeadCopy = newHead;
        head->next = (head->next)->next;
        head = head->next;
        while(head != NULL) {          
            newHead->next = head->next;
            newHead = newHead->next;
            
            head->next = (head->next)->next;
            head = head->next;
        }
        return newHeadCopy;
    }
};