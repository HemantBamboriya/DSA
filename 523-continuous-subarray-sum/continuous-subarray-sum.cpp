class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=-1;
        int prefsum=0;
        for(int i=0;i<nums.size();i++){
            prefsum += nums[i];
            int required= prefsum %k;
            if(mp.find(required)!=mp.end()){
                if(i-mp[required]>=2){
                    return true;
                }
            }else{

            mp[required]=i;
        }
        }
        return false;
    }
};