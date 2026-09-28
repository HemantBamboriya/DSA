class Solution {
public:
    int maxDepth(string s) {
        int maxD=0;
        int maxd=0;
        for(char ch:s){
            if(ch=='('){
                maxd++;
            }else if(ch==')'){
                maxD=max(maxD,maxd);
                maxd--;
            }else{
                continue;
            }
        }
        return maxD;
    }
};