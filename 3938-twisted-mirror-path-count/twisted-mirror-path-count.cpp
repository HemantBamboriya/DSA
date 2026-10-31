class Solution {
public:
int solve(vector<vector<int>>&grid,int i,int j,int cameFrom,int m,int n,int mod,vector<vector<vector<int>>>&dp){
    if(i>=m || j>=n){
        return 0;
    }
    if(i==m-1 && j==n-1){
        return 1;
    }

    if(dp[i][j][cameFrom]!=-1) return dp[i][j][cameFrom];
    int totalPathCount=0;
    if(grid[i][j]==1){
        if(cameFrom==1){
         totalPathCount = solve(grid,i+1,j,0,m,n,mod,dp);
        }else{
            totalPathCount = solve(grid,i,j+1,1,m,n,mod,dp);
        }

    }else{
        totalPathCount += solve(grid,i+1,j,0,m,n,mod,dp)%mod;
    totalPathCount += solve(grid,i,j+1,1,m,n,mod,dp)%mod;
    }


   

    return dp[i][j][cameFrom]=totalPathCount%mod;
}



    int uniquePaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n= grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(2,-1)));

        int up=0;
        int left=1;
        int mod=1e9+7;

        return solve(grid,0,0,up,m,n,mod,dp);
        
    }
};