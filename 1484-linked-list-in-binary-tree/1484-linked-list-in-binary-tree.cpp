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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool solve(ListNode* head,ListNode* temp,TreeNode* root){
        if(!temp){
            return true;
        }
        if(!root){
            return false;
        }
        if(temp->val==root->val){
            temp=temp->next;
        }
        else if(head->val==root->val){
            head=head->next;
        }
        else{
            temp=head;
        }
        bool left=solve(head,temp,root->left);
        bool right=solve(head,temp,root->right);
        return (left || right);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root && !head){
            return true;
        }
        ListNode* temp=head;
        return solve(head,temp,root);
    }
};