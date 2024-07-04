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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* anshead=head->next;
        ListNode* temp=head->next;
        while(temp){
            int sum=0;
            while(temp->val!=0){
                sum+=temp->val;
                temp=temp->next;
            }
            anshead->val=sum;
            temp=temp->next;
            anshead->next=temp;
            anshead=anshead->next;
        }
        return head->next;
    }
};