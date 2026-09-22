class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int required=target-nums[i];
            if(mp.find(required)!=mp.end()){
                return {i,mp[required]};
            }else{
                mp[nums[i]]=i;
            }
        }

        return {-1,-1};
    }
};