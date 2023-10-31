class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n=pref.size();
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            if(i==0 || pref[i-1]==0){
                arr[i]=pref[i];
            }
            else if(pref[i]==0){
                arr[i]=pref[i-1];
            }
            else{
                arr[i]=pref[i-1] ^ pref[i];
            }
        }
        return arr;
    }
};