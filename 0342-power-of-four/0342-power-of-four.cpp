class Solution {
public:
    bool isPowerOfFour(int n) {
        int pos=-1;
        int sbit=0;
        for(int i=0;i<32;i++){
            if(n & (1<<i)){
                sbit++;
                pos=i+1;
            }
        }
        return (sbit==1 && pos%2 == 1);
    }
};