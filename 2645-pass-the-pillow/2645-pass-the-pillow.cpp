class Solution {
public:
    int passThePillow(int n, int time) {
        int x=time%(n-1);
        int y=time/(n-1);
        if(y & 1){
            return (n-x);
        }
        else{
            return 1+x;
        }
    }
};