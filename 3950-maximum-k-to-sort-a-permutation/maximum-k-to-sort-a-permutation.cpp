class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        int k=-1;// k=-1 because all bits are set in that
        for(int i=0;i<n;i++){
            if(nums[i]!=i){
               //take and of all misplaced bits
               k= (k & nums[i]); 
            }
        }
        return k==-1?0:k;
    }
};