class Solution {
public:
int minCoinChange(int index,int target,vector<int>&coins,vector<vector<int>>&dp){
    if(index==0){
        if(target%coins[index]==0){
            return target/coins[0];
        }else{
            return 1e9;
        }
    }
    if(dp[index][target]!=-1) return dp[index][target];
    int nottake=minCoinChange(index-1,target,coins,dp);
    int take=INT_MAX;
    if(coins[index]<=target){
        take= 1+minCoinChange(index,target-coins[index],coins,dp);
    }
    return dp[index][target]=min(take,nottake);
}

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=minCoinChange(n-1,amount,coins,dp);
        if(ans==1e9){
            return -1;
        }
        return ans;
        
    }
};