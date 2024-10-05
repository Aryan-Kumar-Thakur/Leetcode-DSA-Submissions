class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        if(m>n){
            return 0;
        }
        vector<int> arr1(26,0);
        vector<int> arr2(26,0);
        for(int i=0;i<m;i++){
            arr1[s1[i]-'a']++;
            arr2[s2[i]-'a']++;
        }
        for(int i=m;i<n;i++){
            if(arr1==arr2){
                return 1;
            }
            arr2[s2[i-m]-'a']--;
            arr2[s2[i]-'a']++;
        }
        if(arr1==arr2){
            return 1;
        }
        return 0;
    }
};