class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int curr=nums1[0];
        bool hasOdd=false;
        for(int num:nums1){
            if(num<curr){
                curr=num;
            }
            if(num%2==1){
                hasOdd=true;
            }
        }
        if(curr%2==1){
            return true;
        }
        return !hasOdd;
        
    }
};