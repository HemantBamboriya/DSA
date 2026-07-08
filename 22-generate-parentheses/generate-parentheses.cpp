class Solution {
public:

void generateValidParenthesis(int n,int oc,int cc,string s,vector<string>&ans){
    if(oc==n && cc==n){
      ans.push_back(s);
      return;
    }
    if(oc<n){
        generateValidParenthesis(n,oc+1,cc,s+'(',ans);
    }
    if(cc<oc){
        generateValidParenthesis(n,oc,cc+1,s+')',ans);
    }
}


    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        generateValidParenthesis(n,0,0,"",ans);
        return ans;
        
    }
};