class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        map<int,int> mp;
        string ans(n,'$');
        for(auto it:s){
            mp[it]++;
        }
        char maxchar;
        int maxi=0;
        for(auto it:mp){
            if(it.second > maxi){
                maxi=it.second;
                maxchar=it.first;
            }
        }
        if(maxi > (n+1)/2){
            return "";
        }
        int i=0;
        while(mp[maxchar] > 0){
            ans[i]=maxchar;
            mp[maxchar]--;
            i+=2;
        }
        for(auto it:mp){
            while(it.second > 0){
                if(i>=n) i=1;
                ans[i]=it.first;
                i+=2;
                it.second--;
            }
        }
        return ans;
    }
};