class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
       // unordered_map<int,vector<int>>mp;
       vector<int>ans;
        for(int i=0;i<nums.size();i++){
           // mp[nums[i]].push_back(i);
           if(target==nums[i]){
            ans.push_back(i);
           }
        }
        return ans;
        
    }
};