class Solution {
    bool dfs(int node, int parentset, vector<vector<int>>& graph,
             vector<int>& setbelong) {
        setbelong[node] = parentset;
        for (auto it : graph[node]) {
            if (setbelong[it] == -1) {
                if (dfs(it, !parentset, graph, setbelong)) {
                    return true;
                }
            } else if (setbelong[it] == parentset) {
                return true;
            }
        }
        return false;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> setbelong(n, -1);
        for (int i = 0; i < n; i++) {
            if (setbelong[i] == -1) {
                if (dfs(i, 0, graph, setbelong)) {
                    return false;
                }
            }
        }
        return true;
    }
};