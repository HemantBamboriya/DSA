class Solution {
public:
void dfs(int row,int col,int n,int m,vector<vector<int>>&ans,vector<vector<int>>&image,int newColor,int delrow[],int delcol[],int iniColor){
    ans[row][col]=newColor;
    for(int i=0;i<4;i++){
        int nrow=row+delrow[i]; 
        int ncol=col+delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==iniColor && ans[nrow][ncol]!=newColor){
            dfs(nrow,ncol,n,m,ans,image,newColor,delrow,delcol,iniColor);
        }
    }
}

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>ans=image;
        int iniColor=image[sr][sc];
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        dfs(sr,sc,n,m,ans,image,color,delrow,delcol,iniColor);
        return ans;
        
    }
};