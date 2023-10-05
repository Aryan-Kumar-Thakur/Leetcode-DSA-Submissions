class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0;
        int x=INT_MAX,y=INT_MAX;
        vector<int> ans;
        int n=nums.size();
        for(auto it:nums){
            if(cnt1==0 && y!=it){
                x=it;
                cnt1++;
            }
            else if(cnt2==0 && x!=it){
                y=it;
                cnt2++;
            }
            else if(x==it){
                cnt1++;
            }
            else if(y==it){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0,cnt2=0;
        int val=(n/3)+1;
        for(auto it:nums){
            if(x==it){
                cnt1++;
            }
            if(y==it){
                cnt2++;
            }
            if(cnt1==val){
                ans.push_back(it);
                cnt1=0;
                x=INT_MAX;
            }
            if(cnt2==val){
                ans.push_back(it);
                cnt2=0;
                y=INT_MAX;
            }
        }
        return ans;
    }
};