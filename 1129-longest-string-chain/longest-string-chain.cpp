class Solution {
public:
bool checkPossible(string s1,string s2){
    if(s1.size()!=1+s2.size()){
        return false;
    }
    int first=0;
    int second=0;
    while(first<s1.size()){
        if(second<s2.size() && s1[first]==s2[second]){
            first++;
            second++;
        }else{
            first++;
        }
    }
    if(first==s1.size() && second==s2.size()) return true;
    return false;

}

    int longestStrChain(vector<string>& words) {
        int maxi=1;
        int n=words.size();
        sort(words.begin(),words.end(),[](string & s1,string &s2){
            return s1.length()<s2.length();

        });
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(checkPossible(words[i],words[prev]) && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};