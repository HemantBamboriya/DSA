class Solution {
public:

void solve(int idx,vector<int>&candidates,int target,vector<vector<int>>&result,vector<int>&temp){
  
      if(target==0){
        result.push_back(temp);
        result;
      }
   for(int i=idx;i<candidates.size();i++){
    if(i>idx && candidates[i]==candidates[i-1]){
        continue;
    }
    if(candidates[i]>target){
        break;
    }
    temp.push_back(candidates[i]);
    solve(i+1,candidates,target-candidates[i],result,temp);
    temp.pop_back();

   }
}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>result;
        vector<int>temp;
        solve(0,candidates,target,result,temp);
         //set<vector<int>>st(result.begin(),result.end());
         //vector<vector<int>>ans(st.begin(),st.end());
        return result;
        
    }
};