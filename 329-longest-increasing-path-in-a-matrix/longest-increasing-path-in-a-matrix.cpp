class Solution {
public:
int solve(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp,int n,int m){
    int ans=1;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    if(dp[i][j]!=-1) return dp[i][j];
    for(int ik=0;ik<4;ik++){
        int nrow= i+dx[ik];
        int ncol=j+dy[ik];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && matrix[nrow][ncol]>matrix[i][j]){
            ans=max(ans,1+solve(nrow,ncol,matrix,dp,n,m));
        }
    }
    return dp[i][j]=ans;

}

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,solve(i,j,matrix,dp,n,m));

            }
        }
        return ans;
    }
};