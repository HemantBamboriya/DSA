class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
       int totalJumps=0;
       int currentEnd=0;
       int coverage=0;
       for(int i=0;i<nums.size()-1;i++){
        coverage=max(coverage,i+nums[i]);
        if(currentEnd==i){
            totalJumps++;
            currentEnd=coverage;
        }
       }
       return totalJumps;
    }
};