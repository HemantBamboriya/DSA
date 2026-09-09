class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        mp[0]=-1;
        int currSum=0;
        int count=0;
        int end=-1;
        for(int i=0;i<nums.size();i++){
            currSum += nums[i];
            if(mp.find(currSum-target)!=mp.end() && mp[currSum-target]>=end){
                end=i;
                count++;
            }
            mp[currSum]=i;
        }
        return count;
    }
};