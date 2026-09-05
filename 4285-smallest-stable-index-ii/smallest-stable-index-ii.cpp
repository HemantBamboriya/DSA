class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        if(nums.size()==1){
            return 0;
        }
        int n=nums.size();
        vector<int>suffMin(nums.size());
        suffMin[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffMin[i]=min(nums[i],suffMin[i+1]);
        }
        int ans=-1;
        int currMax=nums[0];
        for(int i=0;i<n;i++){
            currMax=max(currMax,nums[i]);
            if(currMax-suffMin[i]<=k){
                return i;
            }

        }
        return ans;
        
    }
};