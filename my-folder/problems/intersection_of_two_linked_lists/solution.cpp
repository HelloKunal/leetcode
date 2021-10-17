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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *Iter1 = headA, *Iter2 = headB;
        
        if(!headA || !headB) return NULL;
        
        while(Iter1 != Iter2) {
            Iter1 = Iter1->next;
            Iter2 = Iter2->next;
            
            if(Iter1 == Iter2) {
                return Iter1; // that is any
            }
            
            if(!Iter1) Iter1 = headB;
            if(!Iter2) Iter2 = headA;
        }
        
        return Iter1; // same as above Iter1 == Iter2
    }
};