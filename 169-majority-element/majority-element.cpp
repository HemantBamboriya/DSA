class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element=nums[0];
        int count=1;
        for(int num:nums){
            if(num==element){
                count++;
            }else{
                count--;
                if(count==0){
                    element=num;
                    count=1;
                }
            }
        }
        return element;
        
    }
};