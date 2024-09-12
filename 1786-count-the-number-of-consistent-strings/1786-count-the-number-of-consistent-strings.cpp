class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int n=words.size();
        map<char,int> mp;
        int cnt=0;
        for(int i=0;i<allowed.size();i++){
            mp[allowed[i]]++;
        }
        for(int i=0;i<n;i++){
            bool f=1;
            for(int j=0;j<words[i].size();j++){
                if(mp.find(words[i][j])==mp.end()){
                    f=0;
                    break;
                }
            }
            if(f){
                cnt++;
            }
        }
        return cnt;
    }
};