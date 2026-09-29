class Solution {
public:
bool validPath(int i,int j,int n,int m,vector<vector<char>>&grid,vector<vector<vector<int>>>&dp,int count){
    
    if(i>=n || j>=m){
        return false;
    }
    if(grid[i][j]=='('){
        count++;
    }else{
        count--;
    }
    if(count<0){
        return false;
    }

    if(i==n-1 && j==m-1){
        return count==0;
    }
    if(dp[i][j][count]!=-1) return dp[i][j][count];

   
        return dp[i][j][count]= validPath(i+1,j,n,m,grid,dp,count)||validPath(i,j+1,n,m,grid,dp,count);
    
    
}

    bool hasValidPath(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==')') return false;
        int len=n+m-1;
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(len+1,-1)));
        return validPath(0,0,n,m,grid,dp,0);
        
    }
};