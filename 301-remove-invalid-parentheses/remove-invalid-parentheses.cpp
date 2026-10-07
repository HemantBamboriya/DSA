class Solution {
public:
int n;
unordered_set<string>st;
int maxLen;

void solve(int i,string & s,string & curr, int count){
    if(count<0){
        return;
    }
    if(i==n){
        if(count==0){
            if(maxLen<curr.length()){
                maxLen=curr.length();
                st.clear();
            }
            if(curr.length()==maxLen){
                st.insert(curr);
            }
        }
        return;
    }

    if(s[i]!='(' && s[i]!=')'){
        curr.push_back(s[i]);
        solve(i+1,s,curr,count);
        curr.pop_back();
        return;
    }
    curr.push_back(s[i]);
    solve(i+1,s,curr,count+(s[i]=='('?1:-1));
    curr.pop_back();
    solve(i+1,s,curr,count);

}

    vector<string> removeInvalidParentheses(string s) {
        n=s.length();
        st.clear();
        maxLen=0;

        string curr="";
        solve(0,s,curr,0);
        return vector<string>(begin(st),end(st));
        
    }
};