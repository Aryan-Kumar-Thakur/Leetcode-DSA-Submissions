class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        int thirdele=INT_MIN;
        for(int i=n-1;i>=0;i--){
            if(nums[i] < thirdele){
                return true;
            }
            while(!st.empty() && nums[i] > st.top()){
                thirdele=st.top();
                st.pop();
            }
            st.push(nums[i]);

        }
        return false;
    }
};