class Solution {
public:
bool isPalindrome(int i,int j, string &s){
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
    
}

// int solve(int i,int n,string & s,vector<int>&dp){
//     if(i==n) return 0;
//         int Minans=INT_MAX;
//     if(dp[i]!=-1) return dp[i];

//     for(int j=i;j<n;j++){
//         if(isplaindrome(i,j,s)){
//           int   ans = 1+ solve(j+1,n,s,dp);
//             Minans=min(ans,Minans);
//         }
//     }
//     return dp[i]=Minans;
// }

    int minCut(string s) {
        int n=s.length();
        // vector<int>dp(n,-1);
        // return solve(0,n,s,dp)-1;
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int mini=INT_MAX;
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s)){
                    int ans=1+dp[j+1];
                    mini=min(mini,ans);
                }
                dp[i]=mini;
            }
        }
return dp[0]-1;
    }
};