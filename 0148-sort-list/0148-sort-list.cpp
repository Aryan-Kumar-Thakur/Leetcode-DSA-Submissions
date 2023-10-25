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

    ListNode* findmid(ListNode* head){
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* head1,ListNode* head2){
        if(!head1){
            return head2;
        }
        if(!head2){
            return head1;
        }
        ListNode* ans=new ListNode (-1);
        ListNode* temp=ans;
        ListNode* temp1=head1,*temp2=head2;
        while(temp1 && temp2){
            if(temp1->val <= temp2->val){
                temp->next=temp1;
                temp=temp1;
                temp1=temp1->next;
            }
            else{
                temp->next=temp2;
                temp=temp2;
                temp2=temp2->next;
            }
        }
        while(temp1){
            temp->next=temp1;
            temp=temp1;
            temp1=temp1->next;
        }
        while(temp2){
            temp->next=temp2;
            temp=temp2;
            temp2=temp2->next;
        }
        ans=ans->next;
        return ans;
    }
    ListNode* mergesort(ListNode* head){
        if(!head || !head->next){
            return head;
        }
        ListNode* head1,*head2;
        ListNode* mid=findmid(head);
        head1=head;
        if(mid->next){
           head2=mid->next;
        }
        mid->next=NULL;
        head1=mergesort(head1);
        head2=mergesort(head2);
        ListNode* anshead = merge(head1,head2);
        return anshead;
    }
public:
    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
};