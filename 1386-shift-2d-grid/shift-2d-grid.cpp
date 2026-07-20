class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
       //last wale ko store kar lete hai then swap karte hai 
       int n=grid.size();//row
       int m=grid[0].size();//col
       while(k--){
        vector<int>ele(n);
        for(int i=0;i<n;i++){
            ele[i]=grid[i][m-1];
        }
        for(int i=0;i<n;i++){
            for(int j=m-1;j>0;j--){
                swap(grid[i][j],grid[i][j-1]);
            }
        }
        for(int i=0;i<n;i++){
           grid[i][0]=ele[n-i-1];
        }
        for(int i=0;i<n-1;i++){
            grid[i+1][0]=ele[i];
        }
           
       }
       return grid;
    }
};