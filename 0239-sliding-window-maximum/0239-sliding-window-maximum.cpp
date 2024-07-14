class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<k;i++){
            while(!dq.empty() && nums[i]>dq.back()){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }
        for(int i=k;i<n;i++){
            ans.push_back(dq.front());
            if(nums[i-k]==dq.front()){
                dq.pop_front();
            }
            while(!dq.empty() && nums[i]>dq.back()){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }
        ans.push_back(dq.front());
        return ans;
    }
};