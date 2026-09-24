class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            int temp=nums[i];
            int ans=0;
            while(temp>0){
            ans += temp%10;
            temp /=10;
            }
            if(ans==i){
                return i;
            }

        }
        return -1;
        
    }
};