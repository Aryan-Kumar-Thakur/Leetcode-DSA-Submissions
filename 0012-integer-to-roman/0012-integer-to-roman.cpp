class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,char> mp;
        mp[1]='I';
        mp[5]='V';
        mp[10]='X';
        mp[50]='L';
        mp[100]='C';
        mp[500]='D';
        mp[1000]='M';
        int x=-1;
        string ans="";
        while(num>0){
            int a=num%10;
            num/=10;
            x++;
            if(a==1 || a==5){
                int y=pow(10,x);
                ans+=mp[a*y];
            }
            else if(a==4 || a==9){
                int b=1;
                a+=1;
                int y=pow(10,x);
                ans+=mp[a*y];
                ans+=mp[b*y];
            }
            else if(a<4){
                int y=pow(10,x);
                while(a>0){
                    ans+=mp[y];
                    a-=1;
                }
            }
            else if(a<9){
                a-=5;
                int y=pow(10,x);
                while(a>0){
                    ans+=mp[y];
                    a--;
                }
                ans+=mp[5*y];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};