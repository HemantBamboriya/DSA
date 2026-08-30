class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int miniIdx=0;
        int maxiIdx=0;
        for(int i=0;i<nums.size();i++){
            if(nums[miniIdx]>nums[i]){
                 miniIdx=i;
            }
            if(nums[maxiIdx]<nums[i]){
                maxiIdx=i;
            }
        }
        int left=max(miniIdx,maxiIdx)+1;
        int right=n-min(miniIdx,maxiIdx);
        int leftRight=min(miniIdx+1+n-maxiIdx,maxiIdx+1+n-miniIdx);
        return min(left,min(right,leftRight));
        
    }
};