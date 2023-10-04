class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int total_fuel=0;
        int fuelfortrip=0;
        int sindex=0;
        for(int i=0;i<n;i++){
            total_fuel+=gas[i]-cost[i];
            fuelfortrip+=gas[i]-cost[i];
            if(fuelfortrip < 0){
                fuelfortrip=0;
                sindex=i+1;
            }
        }
        return (total_fuel < 0)? -1:sindex;
    }
};