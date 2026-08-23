class Solution {
public:
    string reverseWords(string s) {
        int start=0;
        int end=0;
        int n=s.length();
        reverse(s.begin(),s.end());
        string ans="";
        while(start<n){
            while(start<n && s[start]==' '){
                start++;
            }
            if(start>=n){
                break;
            }
            end=start;
            while(s[end]!=' ' && end<n){
                end++;
            }
            string word;
            for(int i=start;i<end;i++){
                word += s[i];
            }
            reverse(word.begin(),word.end());
            ans += word+" ";
            start=end;
        }
        if(!ans.empty()){
            return ans.substr(0,ans.length()-1);
        }
        return ans;
    }
};