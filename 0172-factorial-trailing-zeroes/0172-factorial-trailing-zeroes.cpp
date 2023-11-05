class Solution {
public:
    int trailingZeroes(int n) {
        // vector<int> arr;
        // arr.push_back(1);
        // for(int i=2;i<=n;i++){
        //     int carry=0;
        //     for(int j=0;j<arr.size();j++){
        //         int val=arr[j]*i+carry;
        //         arr[j]=val%10;
        //         carry=val/10;
        //     }
        //     while(carry){
        //         arr.push_back(carry%10);
        //         carry=carry/10;
        //     }
        // }
        // int i=0;
        // while(arr[i]==0){
        //     i++;
        // }
        // return i;
        int cnt=0;
        for(int i=1;i<=6;i++){
            int x=pow(5,i);
            cnt+=(n/x);
        }
        return cnt;
    }
};