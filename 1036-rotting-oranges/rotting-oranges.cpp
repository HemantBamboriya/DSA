class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m));
        queue<pair<int,pair<int,int>>>q;
        int cntFresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                    vis[i][j]=2;
                }else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1){
                    cntFresh++;
                }
            }
        }
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        int tm=0;
        int count=0;
        while(!q.empty()){
            int t=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            tm=max(tm,t);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=delrow[i]+r;
                int ncol=delcol[i]+c;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                    q.push({t+1,{nrow,ncol}});
                    vis[nrow][ncol]=2;
                    count++;
                }
            }

        }
      if(count!=cntFresh){
        return -1;
      }
      return tm;

        
    }
};