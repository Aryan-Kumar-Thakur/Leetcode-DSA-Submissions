class Solution {
    void topo(vector<int> adj[],vector<int> &indegree,vector<int> &ans,int n){
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> udadj[k+1];
        vector<int> lradj[k+1];
        vector<int> udindeg(k+1,0);
        vector<int> lrindeg(k+1,0);
        for(auto it:rowConditions){
            udadj[it[0]].push_back(it[1]);
            udindeg[it[1]]++;
        }
        for(auto it:colConditions){
            lradj[it[0]].push_back(it[1]);
            lrindeg[it[1]]++;
        }
        vector<int> rtopo;
        vector<int> ctopo;
        topo(udadj,udindeg,rtopo,k);
        topo(lradj,lrindeg,ctopo,k);
        vector<int> pos[k+1];
        // cout<<"row"<<endl;
        vector<vector<int>> ans(k,vector<int>(k,0));
        if(rtopo.size()<k || ctopo.size()<k){
            return {};
        }
        for(int i=0;i<rtopo.size();i++){
            pos[rtopo[i]].push_back(i);
        }
        // cout<<endl;
        // cout<<"col"<<endl;
        for(int i=0;i<ctopo.size();i++){
            pos[ctopo[i]].push_back(i);
        }
        for(int i=1;i<=k;i++){
            int r=pos[i][0];
            int c=pos[i][1];
            ans[r][c]=i;
        }
        return ans;
    }
};