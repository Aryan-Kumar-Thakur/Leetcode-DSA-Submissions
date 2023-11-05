class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int j=0;
        int win=0;
        int n=arr.size();
        for(int i=1;i<n;i++){
            if(arr[j] > arr[i]){
                win++;
            }
            else{
                win=1;
                j=i;
            }
            if(win>=k){
                return arr[j];
            }
        }
        return arr[j];
    }
};