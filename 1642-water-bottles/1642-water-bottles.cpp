class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        int rem=numBottles;
        while(rem>=numExchange){
            ans+=(rem/numExchange);
            rem=(rem/numExchange)+(rem%numExchange);
        }
        return ans;
    }
};