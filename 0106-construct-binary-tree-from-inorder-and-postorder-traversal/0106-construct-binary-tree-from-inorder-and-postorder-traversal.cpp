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
    int ind;
    int find(int val,vector<int> &inorder,int s,int e){
        for(int i=s;i<=e;i++){
            if(inorder[i]==val){
                return i;
            }
        }
        return 0;
    }
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int s,int e){
        if(s>e){
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[--ind]);
        int pos=find(root->val,inorder,s,e);
        root->right=solve(inorder,postorder,pos+1,e);
        root->left=solve(inorder,postorder,s,pos-1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        ind=n;
        return solve(inorder,postorder,0,n-1);
    }
};