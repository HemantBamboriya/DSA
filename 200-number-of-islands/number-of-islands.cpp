class Solution {
public:
void bfs(int row,int col,int n,int m,vector<vector<bool>>&vis,vector<vector<char>>&grid,int delrow[],int delcol[]){
    queue<pair<int,int>>q;
    q.push({row,col});
    vis[row][col]=1;
    while(!q.empty()){
        int r= q.front().first;
        int c= q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nrow= r+delrow[i];
            int ncol= c+delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && vis[nrow][ncol]==0){
                q.push({nrow,ncol});
                vis[nrow][ncol]=1;
            }
        }


    }
}

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};

        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                   bfs(i,j,n,m,vis,grid,delrow,delcol);
                   count++;
                }
            }
        }
        return count;
    }
};