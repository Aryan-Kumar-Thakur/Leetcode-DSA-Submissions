class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt=0;
        for(auto it:details){
            int age=0;
            for(int i=11;i<13;i++){
                age=age*10+it[i]-'0';
            }
            if(age>60){
                cnt++;
            }
        }
        return cnt;
    }
};