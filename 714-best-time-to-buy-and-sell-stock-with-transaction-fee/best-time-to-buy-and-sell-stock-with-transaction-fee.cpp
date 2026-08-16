class Solution {
public:
int solve(int idx,int buy,vector<int>&prices,int fee,vector<vector<int>>&dp){
    if(idx==prices.size()){
        return 0;
    }
    if(dp[idx][buy]!=-1) return dp[idx][buy];
    int profit=0;
    if(buy){
        profit=max(-prices[idx]+solve(idx+1,0,prices,fee,dp),solve(idx+1,1,prices,fee,dp));
    }else{
        profit=max(prices[idx]-fee+solve(idx+1,1,prices,fee,dp),solve(idx+1,0,prices,fee,dp));
    }
    return dp[idx][buy]=profit;


}



    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,prices,fee,dp);
        
    }
};