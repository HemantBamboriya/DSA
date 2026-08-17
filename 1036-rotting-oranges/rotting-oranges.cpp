class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>pq;
        int countFresh=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    pq.push({{i,j},0});
                    visited[i][j]=2;
                }else{
                    visited[i][j]=0;
                }
                if(grid[i][j]==1) countFresh++;
            }
        }
        int tm=0;
        int count=0;
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        while(!pq.empty()){
            int row=pq.front().first.first;
            int col=pq.front().first.second;
            int time=pq.front().second;
            tm=max(tm,time);
            pq.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0 && grid[nrow][ncol]==1){
                    count++;
                    visited[nrow][ncol]=2;
                    pq.push({{nrow,ncol},time+1});
                }
            }
        }
        if(count!=countFresh) return -1;
        return tm;

        
    }
};