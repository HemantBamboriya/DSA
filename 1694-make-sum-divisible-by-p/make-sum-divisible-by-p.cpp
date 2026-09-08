class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long totalSum=0;
        for(int i=0;i<nums.size();i++){
            totalSum += nums[i];
        }
        if(totalSum%p==0){
            return 0;
        }
        int target=totalSum % p;
        unordered_map<int,int>mp;
        mp[0]=-1;
        long long prefSum=0;
        int minL=INT_MAX;
        for(int i=0;i<nums.size();i++){
            prefSum += nums[i];
            int curr=prefSum %p;
            int required= (curr-target+p)%p;
            if(mp.find(required)!=mp.end()){
                minL= min(minL,i-mp[required]);
            }
            mp[curr]=i;
        }
 if(minL==INT_MAX || minL==nums.size()){
    return -1;
 }
 return minL;

        
    }
};