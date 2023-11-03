class Solution {
    int countnodes(int root,vector<int> &leftchild,vector<int> &rightchild){
        if(root == -1){
            return 0;
        }
        return 1 + countnodes(leftchild[root],leftchild,rightchild) + countnodes(rightchild[root],leftchild,rightchild);
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftchild, vector<int>& rightchild) {
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            if(leftchild[i]!=-1 && indegree[leftchild[i]] < 2){
                indegree[leftchild[i]]++;
            }
            else if(leftchild[i]!=-1){
                return false;
            }
            if(rightchild[i]!=-1 && indegree[rightchild[i]] < 2){
                indegree[rightchild[i]]++;
            }
            else if(rightchild[i]!=-1){
                return false;
            }
        }
        int cnt=0;
        int s=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                s=i;
                cnt++;
            }
        }
        if(cnt!=1){
            return false;
        }
        return countnodes(s,leftchild,rightchild) == n;
    }
};