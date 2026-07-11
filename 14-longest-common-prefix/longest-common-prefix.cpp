class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string st=strs[0];
        string end=strs[strs.size()-1];
        string ans="";
        for(int i=0;i<st.size();i++){
            if(st[i]==end[i]){
                ans += st[i];
            }else{
                break;
            }
        }
        return ans;
    }
};