class Solution {
public:
    int maximumSwap(int num) {
        vector<int> arr;
        int maxi=0,maxind=0;
        while(num){
            arr.push_back(num%10);
            num/=10;
        }
        reverse(arr.begin(),arr.end());
        vector<int> b(arr.begin(),arr.end());
        sort(b.begin(),b.end(),greater<int>());
        map<int,int> mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
        }
        // for(auto it:arr){
        //     cout<<it<<endl;
        // }
        // for(auto it:b){
        //     cout<<it<<endl;
        // }
        for(int i=0;i<n;i++){
            if(arr[i]!=b[i]){
                swap(arr[i],arr[mp[b[i]]]);
                break;
            }
        }
        int ans=0;
        for(auto it:arr){
            ans=ans*10+it;
        }
        return ans;
    }
};