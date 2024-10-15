class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        long long ans=0;
        while(k--){
            double ele=pq.top();
            pq.pop();
            ans+=ele;
            ele=ele/(double)3;
            ele=ceil(ele);
            pq.push(ele);
        }
        return ans;
    }
};