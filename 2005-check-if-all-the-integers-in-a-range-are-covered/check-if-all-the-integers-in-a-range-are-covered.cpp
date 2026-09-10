class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        set<int>st;
        for(int j=0;j<ranges.size();j++){
           for(int i=ranges[j][0];i<=ranges[j][1];i++){
            st.insert(i);
           }
        }
      for(int i=left;i<=right;i++){
        if(!st.count(i)){
            return false;
        }
      }
      return true;
    }
};