class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // if(n==1 && relations.size()==0){
        //     return time[0];
        // }
        vector<int> adj[n+1];
        for(int i=0;i<relations.size();i++){
            adj[relations[i][0]].push_back(relations[i][1]);
        }
        vector<int> inorder(n+1,0);
        for(int i=1;i<=n;i++){
            for(auto it:adj[i]){
                inorder[it]++;
            }
        }
        vector<int> maxtime(n+1,0);
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(inorder[i]==0){
                q.push(i);
                maxtime[i]=time[i-1];
            }
        }
        // int cnt=2;
        int res=0;
        while(!q.empty()){
                int ele=q.front();
                q.pop();
                for(auto it:adj[ele]){
                    inorder[it]--;
                    maxtime[it]=max(maxtime[it],maxtime[ele] + time[it-1]);
                    if(inorder[it]==0){
                        q.push(it);
                    }
                }
        }
        for(int i=1;i<=n;i++){
            res=max(res,maxtime[i]);
        }
        return res;
    }
};