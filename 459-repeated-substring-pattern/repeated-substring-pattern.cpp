class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.length();
        vector<int>LPS(n,0);
        int length=0;
        int i=1;
        while(i<n){
            if(s[i]==s[length]){
                length++;
                LPS[i]=length;
                i++;
            }else{
                if(length!=0){
                    length= LPS[length-1];
                }else{
                    i++;
                }
            }
        }
        int patternLen= n- LPS[n-1];
        return LPS[n-1]>0 && n%patternLen==0;    }
};