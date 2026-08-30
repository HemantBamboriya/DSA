class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi1=INT_MIN;
        int maxi2=INT_MIN;
        int maxi1Idx=-1;
        int maxi2Idx=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi1){
                maxi2=maxi1;
                maxi1=nums[i];
                maxi1Idx=i;
            }else if(nums[i]>maxi2 && maxi1Idx!=maxi2Idx){
                maxi2=nums[i];
            }
        }
       return (maxi2-1)*(maxi1-1);
    }
};