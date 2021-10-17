/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fastP = head, *slowP = head;
        
        while(fastP && fastP->next) {
            fastP = (fastP->next)->next;
            slowP = slowP->next;
            
            if(fastP == slowP) return true;
        }
        
        return false;
    }
};