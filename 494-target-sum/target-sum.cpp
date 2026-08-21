class Solution {
public:
int solve(int idx,vector<int>&nums,int tar,vector<vector<int>>&dp){
    if(idx==0){
        if(tar==0 && nums[0]==0) return 2;
        if(tar==0 || nums[0]==tar) return 1;
        return 0;
    }
    if(dp[idx][tar]!=-1) return dp[idx][tar];
    int nottake=solve(idx-1,nums,tar,dp);
    int take=0;
    if(nums[idx]<=tar){
        take=solve(idx-1,nums,tar-nums[idx],dp);
    }
    return dp[idx][tar]=take+nottake;
}

    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totalsum=0;
        for(int x:nums){
            totalsum += x;
        }
        if(totalsum-target<0 || (totalsum-target)%2==1){
            return 0;
        }
        int newtarget=(totalsum-target)/2;
        vector<vector<int>>dp(n,vector<int>(newtarget+1,-1));
        return solve(n-1,nums,newtarget,dp);

        
    }
};