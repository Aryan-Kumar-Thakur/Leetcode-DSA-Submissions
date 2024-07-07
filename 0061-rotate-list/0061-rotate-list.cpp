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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0){
            return head;
        }
        int cnt=0;
        ListNode* temp=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        k=k%cnt;
        if(k==0){
            return head;
        }
        temp=head;
        int n=cnt;
        cnt=1;
        while(cnt < (n-k)){
            cnt++;
            temp=temp->next;
        }
        ListNode* f=temp->next;
        temp->next=NULL;
        temp=f;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=head;
        return f;
    }
};