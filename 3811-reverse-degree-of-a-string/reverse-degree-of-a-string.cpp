class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            int starting=s[i]-'a'+1;
            int ending=27-starting;
            ans += ((i+1) * ending);
        }
        return ans;
    }
};