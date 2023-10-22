class Solution {
    void findprevsmallest(vector<int> &left,vector<int> &nums,stack<int> &st){
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(!st.empty()){
                left[i]=st.top();
            }
            st.push(i);
        }
    }
    void findnextsmallest(vector<int> &right,vector<int> &nums,stack<int> &st){
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(!st.empty()){
                right[i]=st.top();
            }
            st.push(i);
        }
    }
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> left(n,-1);
        vector<int> right(n,n);
        stack<int> st;
        findprevsmallest(left,nums,st);
        while(!st.empty()){
            st.pop();
        }
        findnextsmallest(right,nums,st);
        int ans=0;
        for(int i=0;i<n;i++){
            if(left[i]<k && right[i]>k){
                ans=max(ans,nums[i]*((right[i]-left[i])-1));
            }
        }
        return ans;
    }
};