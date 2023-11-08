class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx==fx && sy==fy && t==1){
            return false;
        }
        // if(fx < sx || fy < sy){
        //     swap(fx,sx);
        //     swap(fy,sy);
        // }
        int x=abs(fx-sx);
        int y=abs(fy-sy);
        int rtime=0;
        rtime+=min(x,y);
        if(fx < sx){
            sx-=rtime;
        }
        else{
            sx+=rtime;
        }
        if(fy < sy){
            sy-=rtime;
        }
        else{
            sy+=rtime;
        }
        // sx+=rtime;
        // sy+=rtime;
        int a=abs(fx-sx);
        int b=abs(fy-sy);
        rtime+=max(a,b);
        return (t >= rtime);
    }
};