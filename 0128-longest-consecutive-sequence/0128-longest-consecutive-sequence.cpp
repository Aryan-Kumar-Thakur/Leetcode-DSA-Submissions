class Solution {
public:
    class dsu {
    public:
        vector<int> parent;
        vector<int> size;
        dsu(int n) {
            parent.resize(n, 0);
            size.resize(n, 1);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
        int find_ul_parent(int u) {
            if (parent[u] == u) {
                return u;
            }
            return parent[u] = find_ul_parent(parent[u]);
        }
        void union_by_size(int u, int v) {
            int up_u = find_ul_parent(u);
            int up_v = find_ul_parent(v);
            if (up_u == up_v){
                return;
            }
            if (size[up_u] < size[up_v]) {
                swap(up_u, up_v);
            }
            size[up_u] += size[up_v];
            parent[up_v] = up_u;
        }
        int findmax(){
            int ans=0;
            for(auto it:size){
                ans=max(it,ans);
            }
            return ans;
        }
    };
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        dsu d1(n);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if(mp.find(nums[i])!=mp.end()) continue;
            mp[nums[i]]=i;
            if (mp.find(nums[i] + 1) != mp.end()) {
                d1.union_by_size(i, mp[nums[i] + 1]);
            }
            if (mp.find(nums[i] - 1) != mp.end()) {
                d1.union_by_size(i, mp[nums[i] - 1]);
            }
        }
        return d1.findmax();
    }
};