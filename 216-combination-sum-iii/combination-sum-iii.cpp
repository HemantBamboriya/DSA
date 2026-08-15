class Solution {
public:
void solve(int idx,vector<int>&nums,int target,vector<vector<int>>&ans,vector<int>&temp,int count,int k){
    if(count>k){
        return;
    }
    if(target==0 && count==k){
        ans.push_back(temp);
        return;
    }
    for(int i=idx;i<nums.size();i++){
        if(i>idx && nums[i]==nums[i-1]){
            continue;
        }
        if(nums[i]>target){
            break;
        }
        temp.push_back(nums[i]);
        solve(i+1,nums,target-nums[i],ans,temp,count+1,k);
        temp.pop_back();
    }
}

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        int target=n;
        int count=0;
        vector<int>nums={1,2,3,4,5,6,7,8,9};
        solve(0,nums,target,ans,temp,count,k);
        return ans;
    }
};