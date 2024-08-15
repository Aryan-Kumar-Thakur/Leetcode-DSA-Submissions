class Solution {
    bool bfs(int node,vector<vector<int>>& graph,vector<int> &setbelong){
        setbelong[node]=0;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int ele=q.front();
            q.pop();
            for(auto it:graph[ele]){
                if(setbelong[it]==-1){
                    setbelong[it]=!setbelong[ele];
                    q.push(it);
                }
                else if(setbelong[it]==setbelong[ele]){
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> setbelong(n,-1);
        for(int i=0;i<n;i++){
            if(setbelong[i]==-1){
                if(bfs(i,graph,setbelong)){
                    return false;
                }
            }
        }
        return true;
    }
};