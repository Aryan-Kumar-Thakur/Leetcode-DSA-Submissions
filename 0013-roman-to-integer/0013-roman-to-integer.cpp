class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int n=s.size();
        int ind=0;
        int ans=0;
        while(ind<n){
            if(ind<n-1 && mp[s[ind+1]]>mp[s[ind]]){
                ans+=mp[s[ind+1]]-mp[s[ind]];
                ind++;
            }
            else{
                ans+=mp[s[ind]];
            }
            ind++;
        }
        return ans;
    }
};