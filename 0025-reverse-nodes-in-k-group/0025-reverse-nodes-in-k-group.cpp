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
        if(!head || k==1){
            return head;
        }
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* f=NULL;
        int cnt=1;
        while(curr!=NULL && cnt<=k){
            cnt++;
            curr=curr->next;
        }
        if(cnt<=k){
            return head;
        }
        cnt=1;
        curr=head;
        while(curr && cnt<=k){
            f=curr->next;
            curr->next=prev;
            prev=curr;
            curr=f;
            cnt++;
        }
        if(f){
            head->next=reverseKGroup(f,k);
        }
        return prev;
    }
};