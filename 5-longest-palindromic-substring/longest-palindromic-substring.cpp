class Solution {
public:
int t[1001][1001];
bool isPalindrome(int i,int j,string &s){
    if(i>=j) return true;
    if(t[i][j]!=-1) return t[i][j];
    if(s[i]==s[j]){
        return t[i][j]=isPalindrome(i+1,j-1,s);
    }
    return t[i][j]= false;
}
    string longestPalindrome(string s) {
        int n=s.length();
        memset(t,-1,sizeof(t));
        int maxlength=0;
        int startIndex=-1;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s)){
                    if(j-i+1>maxlength){
                       maxlength=j-i+1;
                       startIndex=i;
                    }
                }
            }
        }
        return s.substr(startIndex,maxlength);
        
    }
};