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
        Node* anshead=NULL,*anstail=NULL;
        Node* temp=head;
        while(temp){
            Node* ele=new Node(temp->val);
            if(anshead==NULL){
                anshead=anstail=ele;
            }
            else{
                anstail->next=ele;
                anstail=ele;
            }
            temp=temp->next;
        }
        Node* temp1=head,*temp2=anshead;
        while(temp1){
            Node* for1=temp1->next;
            temp1->next=temp2;
            Node* for2=temp2->next;
            temp2->next=for1;
            temp1=for1;
            temp2=for2;
        }
        temp1=head;
        while(temp1){
            if(temp1->next){
            if(temp1->random){
            temp1->next->random=temp1->random->next;
            }
            }
            temp1=temp1->next->next;
        }
        temp1=head,temp2=anshead;
        while(temp1){
            temp1->next=temp2->next;
            if(temp1->next){
            temp2->next=temp1->next->next;
            }
            temp2=temp2->next;
            temp1=temp1->next;
        }
        return anshead;
    }
};