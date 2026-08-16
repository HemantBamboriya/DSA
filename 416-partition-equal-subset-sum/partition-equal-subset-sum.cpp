class Solution {
public:
bool solve(int idx,vector<int>&nums,int target,vector<vector<int>>&dp){
    if(target==0) return true;
    if(idx==0) return target==nums[0];
    if(dp[idx][target]!=-1) return dp[idx][target];
    bool take=false; 
    if(nums[idx]<=target){
        take=solve(idx-1,nums,target-nums[idx],dp);
    }
    bool nottake=solve(idx-1,nums,target,dp);
    return dp[idx][target]=take||nottake;


}

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int x:nums){
            sum += x;
        }
        if(sum%2==1) return false;
        int newSum=sum/2;
        vector<vector<int>>dp(n,vector<int>(newSum+1,0));
      //  return solve(n-1,nums,newSum,dp); 
      for(int i=0;i<n;i++){
        dp[i][0]=true;
      }
      if(nums[0]<=newSum) dp[0][nums[0]]=true;
      for(int i=1;i<n;i++){
        for(int tar=1;tar<=newSum;tar++){
            bool nottake=dp[i-1][tar];
            bool take=false;
            if(nums[i]<=tar){
                take=dp[i-1][tar-nums[i]];
            }
            dp[i][tar]=take||nottake;

        }
      }
      return dp[n-1][newSum];
    }
};