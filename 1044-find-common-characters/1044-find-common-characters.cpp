class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        string ans=words[0];
        int n=words.size();
        for(int i=1;i<n;i++){
            unordered_map<char,int> mp;
            string out="";
            for(auto it:ans){
                mp[it]++;
            }
            int m=words[i].size();
            int j=0;
            while(j<m){
                if(mp.find(words[i][j])!=mp.end()){
                    mp[words[i][j]]--;
                    out+=words[i][j];
                    if(mp[words[i][j]]==0){
                        mp.erase(words[i][j]);
                    }
                }
                j++;
            }
            ans=out;
        }
        vector<string> res;
        for(auto it:ans){
            string out="";
            out+=it;
            res.push_back(out);
        }
        return res;
    }
};