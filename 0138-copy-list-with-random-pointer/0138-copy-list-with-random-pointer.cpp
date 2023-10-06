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
        map<Node*,Node*> mp;
        Node* anshead=NULL,*anstail=NULL;
        Node* temp=head;
        while(temp){
            Node* ele=new Node(temp->val);
            if(anshead==NULL){
                anshead = anstail = ele;
            }
            else{
                anstail->next = ele;
                anstail = anstail->next;
            }
            temp=temp->next;
        }
        Node* originalhead=head , *clonehead=anshead;
        while(originalhead){
            mp[originalhead]=clonehead;
            clonehead=clonehead->next;
            originalhead=originalhead->next;
        }
        originalhead=head;
        clonehead=anshead;
        while(originalhead){
            clonehead->random = mp[originalhead->random];
             clonehead=clonehead->next;
            originalhead=originalhead->next;
        }
        return anshead;
    }
};