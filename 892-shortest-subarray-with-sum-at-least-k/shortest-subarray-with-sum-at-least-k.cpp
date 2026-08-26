class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>dq;
        vector<long long>prefSum(n+1,0);
        for(int i=0;i<n;i++){
            prefSum[i+1]=prefSum[i]+nums[i];
        }
        int ans=INT_MAX;
        for(int i=0;i<=n;i++){
            while(!dq.empty() && prefSum[i]-prefSum[dq.front()]>=k){
                ans= min(ans,i-dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && prefSum[dq.back()]>=prefSum[i]){
                dq.pop_back();
            }
            dq.push_back(i);

        }
        
        return ans==INT_MAX?-1:ans;
    }
};