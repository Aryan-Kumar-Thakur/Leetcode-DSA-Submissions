class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        map<vector<int>,int> mp;
        for(auto it:obstacles){
            mp[it]=1;
        }
        //1->N,2->S,3->E,4->W
        int dir=1;
        int x=0,y=0;
        int ans=0;
        int n=commands.size();
        for(int i=0;i<n;i++){
            if(commands[i]==-2){
                switch(dir){
                    case 1: dir=4; break;
                    case 2: dir=3; break;
                    case 3: dir=1; break;
                    case 4: dir=2; break;
                }
            }
            else if(commands[i]==-1){
                switch(dir){
                    case 1: dir=3; break;
                    case 2: dir=4; break;
                    case 3: dir=2; break;
                    case 4: dir=1; break;
                }
            }
            else{
                if(dir==1){
                    while(commands[i]--){
                        if(mp.find({x,y+1})!=mp.end()){
                            break;
                        }
                        y++;
                    }
                }
                else if(dir==2){
                    while(commands[i]--){
                        if(mp.find({x,y-1})!=mp.end()){
                            break;
                        }
                        y--;
                    }
                }
                else if(dir==3){
                    while(commands[i]--){
                        if(mp.find({x+1,y})!=mp.end()){
                            break;
                        }
                        x++;
                    }
                }
                else{
                    while(commands[i]--){
                        if(mp.find({x-1,y})!=mp.end()){
                            break;
                        }
                        x--;
                    }
                }
                ans=max(ans,x*x+y*y);
            }
        }
        return ans;
    }
};