class Solution {
public:
void makesubsets(int index,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
    if(index==nums.size()){
        ans.push_back(temp);
        return;
    }
    temp.push_back(nums[index]);
    makesubsets(index+1,nums,temp,ans);
    temp.pop_back();
    makesubsets(index+1,nums,temp,ans);

}

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        makesubsets(0,nums,temp,ans);
        return ans;
        
    }
};