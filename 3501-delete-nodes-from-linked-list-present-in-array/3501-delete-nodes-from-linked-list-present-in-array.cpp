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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* anshead=new ListNode();
        ListNode* anstail=anshead;
        set<int> st(nums.begin(),nums.end());
        ListNode* temp=head;
        while(temp){
            if(st.find(temp->val)==st.end()){
                ListNode* newnode=new ListNode(temp->val);
                anstail->next=newnode;
                anstail=anstail->next;
            }
            temp=temp->next;
        }
        return (anshead->next);
    }
};