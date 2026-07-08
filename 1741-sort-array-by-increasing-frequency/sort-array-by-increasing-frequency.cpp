class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int num:nums){
            freq[num]++;
        }
        vector<pair<int,int>>num(freq.begin(),freq.end());
        sort(num.begin(),num.end(),[](pair<int,int>&p1,pair<int,int>&p2){
            if(p1.second==p2.second){
                return p1.first>p2.first;
            }
            return p1.second<p2.second;
        });
        vector<int>ans;
        for(auto & it:num){
            int freq=it.second;
            while(freq--){
                ans.push_back(it.first);
            }
        }
     return ans; 
   
   
    }
};