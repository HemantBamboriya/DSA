class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[n-1][i]=matrix[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int leftdia=1e9;
                int rightdia=1e9;
                if(j>0){
                    leftdia= matrix[i][j]+dp[i+1][j-1];
                }
                if(j<n-1){
                    rightdia=matrix[i][j]+dp[i+1][j+1];
                }
                int bottom= matrix[i][j]+dp[i+1][j];
                dp[i][j]=min(leftdia,min(rightdia,bottom));
            }
        }
        int ans=1e9;
        for(int i=0;i<n;i++){
            ans=min(ans,dp[0][i]);
        }
        return ans;
    }
};