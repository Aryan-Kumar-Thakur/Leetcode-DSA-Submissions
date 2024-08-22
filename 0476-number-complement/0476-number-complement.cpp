class Solution {
public:
    int findComplement(int num) {
        long long ans=0;
        int cnt=0;
        while(num){
            int a=(num & 1);
            // cout<<a<<endl;
            a=abs(a-1);
            if(a==1){
                // cout<<i<<endl;
                ans+=pow(2,cnt);
            }
            num=num>>1;
            cnt++;
        }
        return ans;
    }
};