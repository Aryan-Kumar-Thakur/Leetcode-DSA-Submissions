class Solution {
    pair<int,int> solve(int num1,int deno1,int num2,int deno2){
        if(num1==0 && deno1==1){
            return {num2,deno2};
        }
        // cout<<num1<<" "<<deno1<<endl;
        // cout<<num2<<" "<<deno2<<endl;
        int y=deno1*deno2;
        int x=((num1*deno2)+(num2*deno1));
        if(x==0){
            return {0,1};
        }
        for(int i=9;i>=2;i--){
            if(y%i==0 && x%i==0){
                x/=i;
                y/=i;
            }
        }
        return {x,y};
    }
public:
    string fractionAddition(string expression) {
        int cnt=0;
        int n=expression.size();
        int num1=0,num2=0,deno1=0,deno2=0;
        bool neg=0;
        pair<int,int> ans={0,1};
        int i=0;
        while(i<n){
            num1=ans.first;
            deno1=ans.second;
            if(expression[i]=='/' || expression[i]=='+'){
                i++;
                continue;
            }
            else if(expression[i]=='-'){
                neg=1;
                i++;
            }
            else if(num2==0){
                while(expression[i]>='0' && expression[i]<='9'){
                    num2=num2*10+(expression[i]-'0');
                    i++;
                }
                if(neg){
                    num2=(-num2);
                }
            }
            else{
                while(expression[i]>='0' && expression[i]<='9'){
                    deno2=deno2*10+(expression[i]-'0');
                    i++;
                }
            }
            if(num2 && deno2){
                ans=solve(num1,deno1,num2,deno2);
                num2=0,deno2=0;
                neg=0;
                cout<<ans.first<<" "<<ans.second<<endl;
            }
        }
        cout<<ans.first<<" "<<ans.second<<endl;
        string res="";
        res+=to_string(ans.first);
        res+='/';
        res+=to_string(ans.second);
        return res;
    }
};