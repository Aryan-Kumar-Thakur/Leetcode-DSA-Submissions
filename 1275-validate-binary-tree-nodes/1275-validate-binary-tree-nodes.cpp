class Solution {
    int countnodes(int root,vector<int>& leftChild, vector<int>& rightChild){
        if(root==-1){
            return 0;
        }
        return 1+countnodes(leftChild[root],leftChild,rightChild)+countnodes(rightChild[root],leftChild,rightChild);
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n,0);
        int root=-1;
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1 && indegree[leftChild[i]]++ == 1){
                return false;
            }
            else if(rightChild[i]!=-1 && indegree[rightChild[i]]++ == 1){
                return false;
            }
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                if(root!=-1){
                    return false;
                }
                root=i;
            }
        }
        return countnodes(root,leftChild,rightChild) == n;
    }
};