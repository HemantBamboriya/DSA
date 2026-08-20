class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));

        for(int i=n;i>=1;i--){
            for(int j=i;j<=n;j++){
                int maxi=INT_MIN;
                if(i>j) continue;
                for(int ind=i;ind<=j;ind++){
                    int coins= nums[i-1]*nums[ind]*nums[j+1]+dp[i][ind-1]+dp[ind+1][j];
                    maxi=max(maxi,coins);
                }
                dp[i][j]=maxi;
            }
        }
        return dp[1][n];
    }
};