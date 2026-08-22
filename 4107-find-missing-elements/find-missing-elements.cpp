class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
       int largest=INT_MIN;
       int smallest=INT_MAX;
       for(int i=0;i<nums.size();i++){
        largest=max(largest,nums[i]);
        smallest=min(smallest,nums[i]); 
       }
        set<int>st(nums.begin(),nums.end());
        for(int i=smallest;i<largest;i++){
            if(st.count(i)>0){
                continue;
            }else{
                ans.push_back(i);
            }
        }
        return ans;
    }
};