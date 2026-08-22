class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int>st;
        int n=nums.size();
        int remove=n-k;
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && st.top()>nums[i] && remove>0){
                st.pop();
                remove--;
            }
            st.push(nums[i]);
        }
        while(!st.empty() && remove>0){
            st.pop();
            remove--;
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};