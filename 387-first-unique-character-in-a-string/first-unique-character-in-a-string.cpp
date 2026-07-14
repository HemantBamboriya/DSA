class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>freq;
        for(char ch:s){
            freq[ch]++;
        }
        int result=-1;
        for(int i=0;i<s.length();i++){
            if(freq[s[i]]==1){
                result=i;
                break;
            }

        }
        return result;
        
    }
};