class Solution {
public:

long long dfs(int row,int col,vector<vector<int>>&grid,int delrow[],int delcol[],int n,int m){
    long long sum = grid[row][col];
    grid[row][col]=0;
    for(int i=0;i<4;i++){
        int nrow= row+delrow[i];
        int ncol= col+delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]>0){
            sum += dfs(nrow,ncol,grid,delrow,delcol,n,m);
        }
    }
    return sum;
}

    int countIslands(vector<vector<int>>& grid, int k) {
         int n=grid.size();
        int m=grid[0].size();
        int count=0;
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0){
                  long long  sum = dfs(i,j,grid,delrow,delcol,n,m);
                    if(sum%k==0){
                        count++;
                    }
                }
            }
        }
        return count;
        
    }
};