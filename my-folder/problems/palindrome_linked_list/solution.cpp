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
    bool isPalindrome(ListNode* head) {
        // find middle
        ListNode *slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = (fast->next)->next;
        }
        
        // now reverse
        ListNode *prev = slow, *temp;
        slow = slow->next, prev->next = NULL; // slow->next = null because this null goes last
        while(slow) {
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        
        // now compare 
        fast = head, slow = prev;
        while(slow) {
            if(fast->val != slow->val) return false;
            else {
                fast = fast->next;
                slow = slow->next;
            }
        }
        
        return true;
    }
};