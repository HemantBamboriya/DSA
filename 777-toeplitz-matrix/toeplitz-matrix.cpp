class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        if(n==1 || m==1) return true;
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
               if(matrix[i][j]!=matrix[i-1][j-1]){
                return false;
               }
            }
        }
        return true;
        
    }
};