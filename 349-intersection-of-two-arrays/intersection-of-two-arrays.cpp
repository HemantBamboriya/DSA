class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>freq;
        for(int num:nums1){
            freq[num]++;
        }
         set<int>ans;
        for(int num:nums2){
         if(freq[num]>=1){
            ans.insert(num);
         }
        }
        vector<int>result;
       for(int x:ans){
        result.push_back(x);
       }
       

        return result;
    }
};