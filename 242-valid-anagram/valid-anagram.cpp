class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() !=t.length()){
            return false;
        }
        unordered_map<char,int>freq;
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
        }
        for(int j=0;j<s.size();j++){
            freq[t[j]]--;
        }
        for(auto & it:freq){
            if(it.second>0){
return false;
            }
        }
        return true;
    }
};