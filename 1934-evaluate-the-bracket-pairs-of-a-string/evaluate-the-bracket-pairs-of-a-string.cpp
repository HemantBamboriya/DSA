class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans="";
        unordered_map<string,string>mp;
        for(auto &it:knowledge){
            mp[it[0]]=it[1];
        }
        for(int i=0;i<s.length();i++){
            string temp="";
            if(s[i]=='('){
                i++;
                while(i<s.length() && s[i]!=')'){
                    temp += s[i];
                    i++;
                }
                  bool isfound=false;
               if(mp.find(temp)!=mp.end()){
                  isfound=true;
                  ans +=mp[temp];
               }else{
                ans += '?';
               }
                isfound=false;
                temp="";
                continue;
            }
            
            ans += s[i];
        }
        return ans;
    }
};