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
    ListNode *detectCycle(ListNode *head) {
        if(!head){
            return head;
        }
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast && fast!=slow){
            fast=fast->next;
            if(fast){
                fast=fast->next;
            }
            slow=slow->next;
        }
        if(!fast){
            return NULL;
        }
        fast=head;
        slow=slow->next;
        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};