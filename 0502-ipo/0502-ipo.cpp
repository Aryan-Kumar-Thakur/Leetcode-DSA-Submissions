class Solution {
    static bool comp(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a < b;
    }

public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({capital[i], profits[i]});
        }
        sort(arr.begin(), arr.end());
        // for(auto it:arr){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        priority_queue<int> pq;
        int i=0;
        for (int j = 0; j < k; ++j) {
            while (i < n && arr[i].first <= w) {
                pq.push(arr[i].second);
                i++;
            }

            if (pq.empty()) {
                break;
            }

            w += pq.top();
            pq.pop();
        }
        return w;
    }
};