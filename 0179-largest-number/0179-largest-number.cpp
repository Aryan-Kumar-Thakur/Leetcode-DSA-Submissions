class Solution {
    static bool comp(int a,int b){
        return to_string(a)+to_string(b) > to_string(b)+to_string(a);
    }
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        int n=nums.size();
        sort(nums.begin(),nums.end(),comp);
        string ans="";
        for(int i=0;i<n;i++){
            ans+=to_string(nums[i]);
        }
        if(ans[0]=='0'){
            return "0";
        }
        return ans;
    }
};