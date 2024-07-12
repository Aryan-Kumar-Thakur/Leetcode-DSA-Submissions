class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n=s.size();
        stack<char> st1;
        stack<char> st2;
        int ans1=0;
        int ans2=0;
        if(x>=y){
            for(int i=0;i<n;i++){
                if(!st1.empty() && st1.top()=='a' && s[i]=='b'){
                    st1.pop();
                    ans1+=x;
                }
                else{
                    st1.push(s[i]);
                }
            }
            while(!st1.empty()){
                if(!st2.empty() && st2.top()=='a' && st1.top()=='b'){
                    st2.pop();
                    ans1+=y;
                }
                else{
                    st2.push(st1.top());
                }
                st1.pop();
            }

        }
        else{
            for(int i=0;i<n;i++){
                if(!st1.empty() && st1.top()=='b' && s[i]=='a'){
                    st1.pop();
                    ans2+=y;
                }
                else{
                    st1.push(s[i]);
                }
            }
            while(!st1.empty()){
                if(!st2.empty() && st2.top()=='b' && st1.top()=='a'){
                    st2.pop();
                    ans2+=x;
                }
                else{
                    st2.push(st1.top());
                }
                st1.pop();
            }
        }
        return max(ans1,ans2);
    }
};