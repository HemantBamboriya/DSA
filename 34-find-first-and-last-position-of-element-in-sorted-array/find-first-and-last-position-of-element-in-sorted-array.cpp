class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1,-1};
        auto second=upper_bound(nums.begin(),nums.end(),target);
        auto first=lower_bound(nums.begin(),nums.end(),target);

        if(first==nums.end() || *first!=target){
            return {-1,-1};
        }
        int low=first-nums.begin();
        int high=second-nums.begin()-1;
        return {low,high};

    }
};