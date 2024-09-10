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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp=head;
        ListNode* anshead=new ListNode();
        ListNode* anstail=anshead;
        while(temp){
            anstail->next=new ListNode(temp->val);
            anstail=anstail->next;
            if(temp->next){
                int x=__gcd(temp->val,temp->next->val);
                anstail->next=new ListNode(x);
                anstail=anstail->next;
            }
            temp=temp->next;
        }
        return (anshead->next);
    }
};