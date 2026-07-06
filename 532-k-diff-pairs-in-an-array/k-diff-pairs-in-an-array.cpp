class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k<0) return 0;
        int ans=0;
        unordered_map<int,int>freq;
        for(int x: nums){
            freq[x]++;
        }
        for(auto & it:freq){
            if(k==0){
                if(it.second>1){
                    ans++;
                }
            }else{
                if(freq.find(it.first+k)!=freq.end()){
                   ans++;
                }
            }
        }
        return ans;
    }
};