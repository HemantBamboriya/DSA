class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(n==1 && m==1 && grid[n-1][m-1]==0) return 1;
          if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;
          
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        q.push({1,{0,0}});
        dist[0][0]=1;
        while(!q.empty()){
            auto it= q.front();
            q.pop();
            int dis=it.first;
            int r=it.second.first;
            int c=it.second.second;
            for(int dr=-1;dr<=1;dr++){
                for(int dc=-1;dc<=1;dc++){
                    int newr=r+dr;
                    int newc=c+dc;
                    if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==0 && 1+dis<dist[newr][newc]){
                        dist[newr][newc]=1+dis;
                        if(newr==n-1 && newc==m-1){
                            return dist[newr][newc];
                        }
                        q.push({dist[newr][newc],{newr,newc}});
                    }
                }
            }

        }
        return -1;
    }
};