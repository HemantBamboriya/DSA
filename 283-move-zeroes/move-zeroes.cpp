class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastnonZero=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                nums[lastnonZero++]=nums[i];
            }
        }
        for(int i=lastnonZero;i<n;i++){
            nums[i]=0;
        }
    }
};