class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st;
        for(auto it:wordList){
            st.insert(it);
        }
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            string ele=q.front().first;
            int cnt=q.front().second;
            q.pop();
            if(ele==endWord){
                return cnt;
            }
            for(int i=0;i<ele.size();i++){
                char ch=ele[i];
                for(char j='a';j<='z';j++){
                    ele[i]=j;
                    if(st.find(ele)!=st.end()){
                        q.push({ele,cnt+1});
                        st.erase(ele);
                    }
                }
                ele[i]=ch;
            }
        }
        return 0;
    }
};