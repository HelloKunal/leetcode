/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode preheader(-1);
        preheader.next = head;
        ListNode* curr = &preheader, *nex, *pre = &preheader;
        
        if(head == NULL || k == 1) return head;
        
        int num = 0;
        while(curr = curr->next) 
            num++;
        
        while(num >= k) {
            curr = pre->next;
            nex = curr->next;
            
            for(int i = 0; i < k-1; i++) {
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
            
            pre = curr;
            num -= k;
        }
        
        return preheader.next;           
    }
};