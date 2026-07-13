class Solution {
public:

void solve(int index,string temp,string digits,unordered_map<char,string>&mp,vector<string>&result){
    if(index>=digits.size()){
        result.push_back(temp);
        return;
    }
    char ch=digits[index];
    string traverse=mp[ch];
    for(int i=0;i<traverse.size();i++){
        temp.push_back(traverse[i]);
        solve(index+1,temp,digits,mp,result);
        temp.pop_back();
    }
}

    vector<string> letterCombinations(string digits) {
        if(digits.length()==0){
            return {};
        }
        unordered_map<char,string>mp;
        string temp="";
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        vector<string>result;
        solve(0,temp,digits,mp,result);
        return result;

        
    }
};