class Solution {
public:
void generatePar(int oc,int cc,int n,string temp,vector<string>&ans){
    if(oc==n && cc==n){
        ans.push_back(temp);
        return;
    }
    if(oc<n){
        generatePar(oc+1,cc,n,temp+'(',ans);
    }
    if(cc<oc){
        generatePar(oc,cc+1,n,temp+')',ans);
    }

}

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp;
         generatePar(0,0,n,temp,ans);
        return ans;
    }
};