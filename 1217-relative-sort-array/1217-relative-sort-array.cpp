class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;
        int n=arr2.size();
        for(int i=0;i<n;i++){
            mp[arr2[i]]=i;
        }
        vector<pair<int,int>> temp;
        int m=arr1.size();
        int cnt=0;
        int j=n;
        for(int i=0;i<m;i++){
            if(mp.find(arr1[i])!=mp.end()){
                temp.push_back({mp[arr1[i]],arr1[i]});
                cnt++;
            }
            else{
                temp.push_back({j++,arr1[i]});
            }
        }
        sort(temp.begin(),temp.end());
        vector<int> ans;
        for(auto it:temp){
            ans.push_back(it.second);
        }
        sort(ans.begin()+cnt,ans.end());
        return ans;
    }
};