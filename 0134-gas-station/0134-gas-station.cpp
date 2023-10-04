class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int startindex=0;
        while(startindex < n){
            bool f=1;
            int g=0;
            g+=gas[startindex];
            int i=(startindex+1)%n;
            int cnt=0;
            while(cnt<=n){
                int c=0;
                if(i==0){
                    c=cost[n-1];
                }
                else{
                    c=cost[i-1];
                }
                g = g - c;
                if(g < 0){
                    f=0;
                    break;
                }
                g+=gas[i];
                i=(i+1)%n;
                cnt++;
            }
            if(f){
                return startindex;
            }
           else{
                if(i > startindex){
                    startindex=i;
                }
                else{
                    break;
                }
           }
        }
        return -1;
    }
};