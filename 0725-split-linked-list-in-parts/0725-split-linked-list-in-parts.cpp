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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            size++;
        }
        int m=size/k;
        int x=size%k;
        int y=0;
        ListNode* anshead=new ListNode();
        ListNode* anstail=anshead;
        temp=head;
        vector<ListNode*> ans;
        while(temp){
            y=m;
            while(temp && y--){
                anstail->next=new ListNode(temp->val);
                anstail=anstail->next;
                temp=temp->next;
            }
            if(temp && x){
                anstail->next=new ListNode(temp->val);
                anstail=anstail->next;
                temp=temp->next;
                x--;
            }
            ans.push_back(anshead->next);
            anshead=new ListNode();
            anstail=anshead;
        }
        while(ans.size()<k){
            ans.push_back(NULL);
        }
        return ans;
    }
};