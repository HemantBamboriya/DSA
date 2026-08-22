class Solution {
public:

void bfs(int row,int col,vector<vector<char>>&grid,vector<vector<int>>&visited,int n,int m){
   queue<pair<int,int>>q;
   q.push({row,col});
   visited[row][col]=1;
   int delrow[]={-1,0,1,0};
   int delcol[]={0,1,0,-1};
   while(!q.empty()){
    int r=q.front().first;
    int c=q.front().second;
    q.pop();
    for(int i=0;i<4;i++){
        int nrow=r+delrow[i];
        int ncol=c+delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0 && grid[nrow][ncol]=='1'){
            q.push({nrow,ncol});
            visited[nrow][ncol]=1;
        }
    }

   }
}

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    count++;
                    bfs(i,j,grid,visited,n,m);
                }

            }
        }
        return count;
    }
};