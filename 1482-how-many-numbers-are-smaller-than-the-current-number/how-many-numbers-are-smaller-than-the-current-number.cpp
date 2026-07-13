class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>vec(nums.begin(),nums.end());
        sort(vec.begin(),vec.end());
        vector<int>ans(nums.size(),0);
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(vec[i])==mp.end()){
                mp[vec[i]]=i;
            }
        }
        for(int i=0;i<nums.size();i++){
            ans[i]=mp[nums[i]];
        }
        return ans;
    }
};