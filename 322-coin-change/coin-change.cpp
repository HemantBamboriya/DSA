class Solution {
public:
int solve(int idx,vector<int>&coins,int target,vector<vector<int>>&dp){
    if(idx==0){
        if(target%coins[0]==0){
            return target/coins[0];
        }
        return 1e9;
    }
    if(dp[idx][target]!=-1) return dp[idx][target];
    int nottake=solve(idx-1,coins,target,dp);
    int take=1e9;
    if(coins[idx]<=target){
        take=1+solve(idx,coins,target-coins[idx],dp);
    }
    return dp[idx][target]=min(take,nottake);
}


    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=solve(n-1,coins,amount,dp);
        if(ans>=1e9) return -1;
        return ans;
        
    }
};