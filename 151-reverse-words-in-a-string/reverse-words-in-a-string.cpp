class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        int start=0;
        int end=0;
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
            while(end<n && s[end]!=' '){
                end++;
            }
            string word="";
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