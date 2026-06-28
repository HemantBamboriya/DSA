class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxreach=0;
        for(int i=0;i<nums.size();i++){
          if(i>maxreach){
            return false;
          }
          maxreach=max(maxreach,i+nums[i]);
          if(maxreach>=n){
            return true;
          }
        }
        return true;
    }
};