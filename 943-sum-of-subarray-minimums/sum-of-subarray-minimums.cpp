class Solution {
public:
vector<int>getNse(vector<int>&arr){
    int n=arr.size();
    vector<int>nse(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(st.empty()){
            nse[i]=n;
        }else{
            nse[i]=st.top();
        }
        st.push(i);
    }
    return nse;
}

vector<int>getPse(vector<int>&arr){
    int n=arr.size();
    vector<int>pse(n);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i]){
            st.pop();
        }
        if(st.empty()){
            pse[i]=-1;
        }else{
            pse[i]=st.top();
        }
        st.push(i);
    }
    return pse;
}


    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>nse=getNse(arr);
        vector<int>pse=getPse(arr);
        long long sum=0;
        int mod=(int)1e9+7;
        for(int i=0;i<n;i++){
            long long left=i-pse[i];
            long long right=nse[i]-i;
            sum = (sum+(arr[i]*right%mod*left%mod)%mod%mod)%mod;
        }
return sum;
        
    }
};