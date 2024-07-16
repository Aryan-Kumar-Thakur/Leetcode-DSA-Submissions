class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() > haystack.size()){
            return -1;
        }
        int k=needle.size();
        for(int i=0;i<=haystack.size()-k;i++){
            if(haystack.substr(i,k)==needle){
                return i;
            }
        }
        return -1;
    }
};