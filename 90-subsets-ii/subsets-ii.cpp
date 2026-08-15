class Solution {
public:

void solve(int idx,vector<int>&nums,vector<vector<int>>&result,vector<int>&temp){
    if(idx==nums.size()){
        result.push_back(temp);
        return ;
    }
    temp.push_back(nums[idx]);
    solve(idx+1,nums,result,temp);
    temp.pop_back();
    solve(idx+1,nums,result,temp);
}

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>result;
        vector<int>temp;
        solve(0,nums,result,temp);
        set<vector<int>>st(result.begin(),result.end());
        vector<vector<int>>res(st.begin(),st.end());
        return res;
        
    }
};