class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int currsum=0;
        int totalsum= n*(n+1)/2;
        for(int i=0;i<n;i++){
            currsum += nums[i];
        }
        return totalsum-currsum;
        
    }
};