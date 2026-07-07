class Solution {
public:

  int tribonacciFind(int n,vector<int>&dp){
    if(n==0) return 0;
        if(n==1 || n==2) return 1;
        
        if(dp[n]!=-1) return dp[n];

        return dp[n]=tribonacciFind(n-1,dp)+tribonacciFind(n-2,dp)+tribonacciFind(n-3,dp);
    
  }

    int tribonacci(int n) {
       vector<int>dp(n+1,-1);
            int ans= tribonacciFind(n,dp);
        return ans;
        
    }
};