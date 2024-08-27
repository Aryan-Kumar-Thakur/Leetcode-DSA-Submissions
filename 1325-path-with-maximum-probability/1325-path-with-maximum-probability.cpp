#define PI pair<double,int>
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> dis(n,0.0);
        vector<PI> adj[n];
        int m=edges.size();
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({succProb[i],edges[i][1]});
            adj[edges[i][1]].push_back({succProb[i],edges[i][0]});
        }
        priority_queue<PI> pq;
        dis[start_node]=1;
        pq.push({1,start_node});
        while(!pq.empty()){
            double prob=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(node==end_node){
                return prob;
            }
            for(auto it:adj[node]){
                if((prob*it.first) > dis[it.second]){
                    dis[it.second] = prob*it.first;
                    pq.push({(prob*it.first),it.second});
                }
            }
        }
        return dis[end_node];
    }
};