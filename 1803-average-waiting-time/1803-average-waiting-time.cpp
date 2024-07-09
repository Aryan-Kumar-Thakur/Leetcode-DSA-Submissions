class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n=customers.size();
        int w=customers[0][0];
        double avgwaiting=0;
        for(auto it:customers){
            w=max(w,it[0]);
            w+=it[1];
            // cout<<w<<endl;
            avgwaiting+=(w-it[0]);
            // cout<<avgwaiting<<endl;
        }
        // cout<<avgwaiting<<endl;
        double ans = (double)(avgwaiting/(double)n);
        return ans;
    }
};