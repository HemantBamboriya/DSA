class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int suffmax=1;
        int prefix=1;
        int maxi=nums[0];
        for(int i=0;i<n;i++){
           if(suffmax==0) suffmax=1;
           if(prefix==0) prefix=1;
            suffmax= suffmax*nums[i];
            prefix= prefix*nums[n-i-1];
            maxi=max(maxi,max(suffmax,prefix));
        }
        return maxi;
    }
};