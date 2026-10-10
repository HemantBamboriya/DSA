class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int k= k1+k2;

        vector<int>diff(1e5+1,0);

        for(int i=0;i<nums1.size();i++){
            int currDiff= abs(nums1[i]-nums2[i]);
            diff[currDiff]++;
        }
        
        for(int i=1e5;i>0 && k>0 ; i--){
            int currOpe=min(k,diff[i]);
            diff[i] -= currOpe;
            diff[i-1] += currOpe;
            k -= currOpe;
        }

        long long ans=0;
        for(int i=1;i<=1e5;i++){
            ans += 1LL * diff[i] * i*i;
        }

return ans;
    }
};