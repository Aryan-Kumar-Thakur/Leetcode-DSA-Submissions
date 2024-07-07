/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return NULL;
        }
        Node* anshead=new Node(head->val);
        Node* anstail=anshead;
        Node* temp=head->next;
        while(temp){
            anstail->next=new Node(temp->val);
            anstail=anstail->next;
            temp=temp->next;
        }
        Node* temp1=head;
        Node* temp2=anshead;
        while(temp1 && temp2){
            Node* f1=temp1->next;
            Node* f2=temp2->next;
            temp1->next=temp2;
            temp1=f1;
            temp2->next=temp1;
            temp2=f2;
        }
        temp1=head;
        while(temp1 && temp1->next){
            if(temp1->random){
                temp1->next->random=temp1->random->next;
            }
            temp1=temp1->next->next;
        }
        temp1=head;
        temp2=anshead;
        while(temp1->next && temp2->next){
            Node* f1=temp1->next->next;
            Node* f2=temp2->next->next;
            temp1->next=f1;
            temp2->next=f2;
            temp1=f1;
            temp2=f2;
        }
        temp1->next=NULL;
        temp2->next=NULL;
        return anshead;
    }
};