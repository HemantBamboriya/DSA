class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=0;
        int j=0;
        while(j<s.size()){
            while(j<s.size() && s[j]==' '){
                j++;
            }
            while(j<s.size() && s[j]!=' '){
                s[i++]=s[j++];
            }
            while(j<s.size() && s[j]==' '){
                s[j++];
            }
            if(j<s.size()){
                s[i++]=' ';
            }
        }
        s.resize(i);
        reverse(s.begin(),s.end());
       int left=0;
       for(int right=0;right<=s.size();right++){
        if(right==s.size() || s[right]==' '){
            left= right ;
            break;
        }
       }
        return left;
    }
};