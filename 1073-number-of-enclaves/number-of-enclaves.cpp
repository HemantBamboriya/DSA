class Solution {
public:
void dfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&visited,int delrow[],int delcol[],int n,int m){
    visited[row][col]=1;
    for(int i=0;i<4;i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==1){
            dfs(nrow,ncol,grid,visited,delrow,delcol,n,m);
        }
    }
}


    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(!visited[0][j] && grid[0][j]==1){
                dfs(0,j,grid,visited,delrow,delcol,n,m);
            }
            if(!visited[n-1][j] && grid[n-1][j]==1){
                dfs(n-1,j,grid,visited,delrow,delcol,n,m);
            }
        }
        for(int i=0;i<n;i++){
            if(!visited[i][0] && grid[i][0]==1){
                dfs(i,0,grid,visited,delrow,delcol,n,m);
            }
            if(!visited[i][m-1] && grid[i][m-1]==1){
                dfs(i,m-1,grid,visited,delrow,delcol,n,m);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};