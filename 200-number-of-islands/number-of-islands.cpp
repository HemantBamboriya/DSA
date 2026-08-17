class Solution {
public:
void bfs(int row,int col,vector<vector<char>>&grid,vector<vector<int>>&visited){
    int n=grid.size();
    int m=grid[0].size();
    queue<pair<int,int>>pq;
    pq.push({row,col});
    visited[row][col]=1;
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};
    while(!pq.empty()){
        int row=pq.front().first;
        int col=pq.front().second;
        pq.pop();
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]=='1'){
                visited[nrow][ncol]=1;
                pq.push({nrow,ncol});
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
                    bfs(i,j,grid,visited);
                }
            }
        }
        return count;
    }
};