class Solution {
    void findnextgreatest(vector<int> &arr,vector<int> &right,stack<int> &st,int n){
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }
            if(!st.empty()){
                right[i]=st.top();
            }
            st.push(i);
        }
    }
public:
    int getWinner(vector<int>& arr, int k) {
        map<int,int> mp;
        int ans=-1;
        int n=arr.size();
        stack<int> st;
        vector<int> right(n,n);
        findnextgreatest(arr,right,st,n);
        int i=0;
        if(arr[0] < arr[1]){
            i=1;
        }
        while(i<n){
            int win=arr[i];
            if(i>0){
                mp[win]=1;
            }
            if(right[i]==n){
                return arr[i];
            }
            mp[win]+=(right[i]-(i+1));
            i=right[i];
            if(mp[win]>=k){
                return win;
            }
        }
        return -1;
    }
};