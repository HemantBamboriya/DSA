class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>lastPosition;
        string result;
        for(char ch:s){
            if(ch=='('){
                lastPosition.push(result.length());
            }else if(ch==')'){
                int length=lastPosition.top();
                lastPosition.pop();
                reverse(result.begin()+length,result.end());
            }else{
                result.push_back(ch);
            }
        }
        return result;
    }
};