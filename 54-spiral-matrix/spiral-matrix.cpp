class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>result;
        if(matrix.empty()){
            return result;
        }
        int srow=0;
        int scol=0;
        int ecol=matrix[0].size()-1;
        int eraw=matrix.size()-1;
        while(srow<=eraw && scol<=ecol){
            for(int i=scol;i<=ecol;i++){
                result.push_back(matrix[srow][i]);
            }
            for(int i=srow+1;i<=eraw;i++){
                result.push_back(matrix[i][ecol]);
            }
            for(int i=ecol-1;i>=scol;i--){
                if(srow==eraw){
                    break;
                }
                result.push_back(matrix[eraw][i]);
            }
            for(int i=eraw-1;i>=srow+1;i--){
                if(scol==ecol){
                    break;
                }
                result.push_back(matrix[i][scol]);
            }
            srow++;
            scol++;
            ecol--;
            eraw--;

        }
        return result;
    }
};