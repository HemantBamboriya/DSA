class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int>nge(n2);
        stack<int>st;
        for(int i=n2-1;i>=0;i--){
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }
            if(st.empty()){
                nge[i]=-1;
            }else{
                nge[i]=st.top();
            }
            st.push(nums2[i]);
        }
        vector<int>ans(n1);
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(nums1[i]==nums2[j]){
                    ans[i]=nge[j];
                }
            }
        }
       return ans; 
    }
};