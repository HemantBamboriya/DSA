class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int minsum=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int sum=nums[i];
            if(sum>0 && l==1){
             minsum= min(minsum,sum);
            } 
            for(int j=i+1;j<nums.size();j++){
                sum += nums[j];
                if(j-i+1>=l && j-i+1<=r && sum>0){
                    minsum= min(minsum,sum);
                }
            }
            if(sum<0){
                sum=0;
            }
        }
        return minsum==INT_MAX?-1:minsum;
    }
};