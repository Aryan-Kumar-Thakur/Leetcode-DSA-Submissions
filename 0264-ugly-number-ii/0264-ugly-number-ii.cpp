class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        unordered_map<long long,long long> mp;
        pq.push(1);
        mp[1]=1;
        vector<long long> prime={2,3,5};
        int cnt=0;
        while(!pq.empty()){
            int ele=pq.top();
            pq.pop();
            cnt++;
            if(cnt==n) return ele;
            for(auto it:prime){
                long long ugly=ele*it;
                if(mp.find(ugly)==mp.end()){
                    pq.push(ugly);
                    mp[ugly]=1;
                }
            }
        }
        return -1;
    }
};