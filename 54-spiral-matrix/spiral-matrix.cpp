class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int scol=0;
        int srow=0;
        int erow=matrix.size();
        int ecol=matrix[0].size();
        while(srow<erow && scol<ecol){
            for(int i=scol;i<ecol;i++){
                ans.push_back(matrix[srow][i]);
            }
            srow++;
            for(int i=srow;i<erow;i++){
                ans.push_back(matrix[i][ecol-1]);
            }
            ecol--;
            if(srow<erow){
            for(int i=ecol-1;i>=scol;i--){
                ans.push_back(matrix[erow-1][i]);
            }
            }
            erow--;
            if(scol<ecol){
            for(int i=erow-1;i>=srow;i--){
                ans.push_back(matrix[i][scol]);
            }
            }
           scol++;


        }
        return ans;
    }
};