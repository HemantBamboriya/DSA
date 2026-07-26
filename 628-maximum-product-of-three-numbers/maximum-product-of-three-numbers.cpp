class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        long long maxPro=INT_MIN;
        int firstNum=INT_MIN;
        int secondNum=INT_MIN;
        int thirdNum=INT_MIN;
        int min1=INT_MAX;
        int min2=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>firstNum){
                thirdNum=secondNum;
                secondNum=firstNum;
                firstNum=nums[i];
            }else if(nums[i]>secondNum){
                thirdNum=secondNum;
                secondNum=nums[i];
            }else if(nums[i]>thirdNum){
                thirdNum=nums[i];
            }
           
           if(nums[i]<min1){
            min2=min1;
            min1=nums[i];
           }else if(nums[i]<min2){
            min2=nums[i];
           }

        }
        return max(firstNum*secondNum*thirdNum,firstNum*min1*min2) ;
    }
};