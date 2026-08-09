class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>result;
        if(p.length()>s.length()){
            return result;
        }
        vector<int>freqP(26,0);
        vector<int>windFreq(26,0);
        for(char ch:p){
            freqP[ch-'a']++;
        }
        int k=p.length();
        for(int i=0;i<k;i++){
            windFreq[s[i]-'a']++;
        }
        if(windFreq==freqP){
            result.push_back(0);
        }
        for(int i=k;i<s.length();i++){
            windFreq[s[i]-'a']++;
            windFreq[s[i-k]-'a']--;
            if(windFreq==freqP){
                result.push_back(i-k+1);
            }
        }
        return result;
    }
};