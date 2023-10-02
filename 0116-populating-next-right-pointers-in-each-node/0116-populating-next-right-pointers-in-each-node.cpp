/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return root;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int x=q.size();
            for(int i=0;i<x;i++){
                Node* ele=q.front();
                q.pop();
                if(i==x-1){
                    ele->next=NULL;
                }
                else{
                    ele->next=q.front();
                }
                if(ele->left){
                    q.push(ele->left);
                }
                if(ele->right){
                    q.push(ele->right);
                }
            }
        }
        return root;
    }
};