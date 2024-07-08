class Solution {
public:
    int findTheWinner(int n, int k) {
        if(k==1){
            return n;
        }
        // if(k==n){
        //     return n-1;
        // }
        deque<int> dq;
        for(int i=0;i<n;i++){
            dq.push_back(i+1);
        }
        while(dq.size()>1){
            int x=k-1;
            while(x--){
                int ele=dq.front();
                dq.pop_front();
                dq.push_back(ele);
            }
            dq.pop_front();
        }
        return dq.front();
    }
};