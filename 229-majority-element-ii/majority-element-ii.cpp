class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0;
        int count2=0;
        int ele1=INT_MIN;
        int ele2=INT_MIN;
        for(int x:nums){
            if(count1==0 && ele2!=x){
                count1++;
                ele1=x;
            }else if(count2==0 && ele1!=x){
                count2++;
                ele2=x;
            }else if(ele1==x){
                count1++;
            }else if(ele2==x){
                count2++;
            }else{
                count1--;
                count2--;
            }
        }
         count1=0;
         count2=0;
        for(int x:nums){
            if(x==ele1){
                count1++;
            }else if(x==ele2){
                count2++;
            }
        }
        vector<int>ans;
        int mini=(int) (nums.size()/3)+1;
        if(count1>=mini){
            ans.push_back(ele1);
        }
        if(count2>=mini){
            ans.push_back(ele2);
        }
        return ans;
        
    }
};