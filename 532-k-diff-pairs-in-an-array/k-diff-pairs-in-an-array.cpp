class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k<0) return 0;
        sort(nums.begin(),nums.end());
        int i=0;
        int j=1;
        int ans=0;
        int n= nums.size();
        while(j<n){
            if(i==j || nums[j]-nums[i]<k){
                j++;
            }else if(nums[j]-nums[i]>k){
                i++;
            }else{
                i++;
                j++;
                ans++;

                while(j<n && nums[j]==nums[j-1]){
                    j++;
                }
            }
        }
return ans;
        
    }
};