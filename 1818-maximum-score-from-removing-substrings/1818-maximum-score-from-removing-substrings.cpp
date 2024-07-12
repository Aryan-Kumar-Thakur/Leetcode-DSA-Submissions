class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n=s.size();
        int acnt=0;
        int bcnt=0;
        int mini=min(x,y);
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]>'b'){
                ans+=min(acnt,bcnt)*mini;
                acnt=0;
                bcnt=0;
            }
            else if(s[i]=='a'){
                if(y>x && bcnt > 0){
                    bcnt--;
                    ans+=y;
                }
                else{
                    acnt++;
                }
            }
            else{
                if(x>y && acnt>0){
                    acnt--;
                    ans+=x;
                }
                else{
                    bcnt++;
                }
            }
        }
        ans+=min(acnt,bcnt)*mini;
        return ans;
    }
};