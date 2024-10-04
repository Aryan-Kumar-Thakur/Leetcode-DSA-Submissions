class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans=0;
        sort(skill.begin(),skill.end());
        int n=skill.size();
        int i=0,j=n-1;
        long long tar=skill[i] + skill[j];
        ans+=(skill[i++]*skill[j--]);
        while(i<=j){
            if(skill[i]+skill[j]!=tar){
                return -1;
            }
            else{
                ans+=(skill[i++]*skill[j--]);
            }
        }
        return ans;
    }
};