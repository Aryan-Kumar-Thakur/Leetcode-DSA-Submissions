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
    ListNode* reverseLL(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr){
            ListNode* f=curr->next;
            curr->next=prev;
            prev=curr;
            curr=f;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* head2=slow->next;
        slow->next=NULL;
        head2=reverseLL(head2);
        while(head && head2){
            if(head->val != head2->val){
                return false;
            }
            head=head->next;
            head2=head2->next;
        }
        return true;
    }
};