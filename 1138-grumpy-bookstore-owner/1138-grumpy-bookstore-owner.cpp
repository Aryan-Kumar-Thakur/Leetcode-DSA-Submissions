class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum=0;
        int res=0;
        int n=customers.size();
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                sum+=customers[i];
            }
        }
        int i=0,j=0;
        while(j<n){
            if(minutes<=0){
                if(grumpy[i]==1){
                    sum-=customers[i];
                }
                minutes++;
                i++;
            }
            if(minutes>0){
                if(grumpy[j]==1){
                    sum+=customers[j];
                }
            }
            // cout<<sum<<endl;
            res=max(res,sum);
            minutes--;
            j++;
        }
        res=max(res,sum);
        return res;
    }
};