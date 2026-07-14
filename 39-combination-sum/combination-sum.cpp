class Solution {
public:
void solve(int index,int target,vector<vector<int>>&ans,vector<int>&temp,vector<int>&candidates){
    if(index==candidates.size()){
        if(target==0){
            ans.push_back(temp);
        }
            return;
        
    }
    if(candidates[index]<=target){
        temp.push_back(candidates[index]);
        solve(index,target-candidates[index],ans,temp,candidates);
        temp.pop_back();
    }
    solve(index+1,target,ans,temp,candidates);

}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,target,ans,temp,candidates);
        return ans;     
    }
};