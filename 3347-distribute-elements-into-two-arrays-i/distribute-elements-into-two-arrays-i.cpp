class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>arr1;
        vector<int>arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i=2;i<nums.size();i++){
            if(arr1.back()>arr2.back()){
                arr1.push_back(nums[i]);
            }else{
                arr2.push_back(nums[i]);
            }
        }
        int size=arr1.size()+arr2.size();
       vector<int>newArray(size);
       for(int i=0;i<arr1.size();i++){
        newArray[i]=arr1[i];
       }
       for(int i=0;i<arr2.size();i++){
        newArray[arr1.size()+i]=arr2[i];
       }
       return newArray;
    }
};