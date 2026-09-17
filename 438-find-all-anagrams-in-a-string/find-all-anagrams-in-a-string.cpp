class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>result;
        if(p.size()>s.size()){
            return result;
        }
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        for(int i=0;i<p.size();i++){
            freq1[p[i]-'a']++;
        }
        int k=p.size();
        for(int i=0;i<k;i++){
            freq2[s[i]-'a']++;
        }
        if(freq1==freq2){
            result.push_back(0);
        }
        for(int i=k;i<s.size();i++){
            freq2[s[i]-'a']++;
            freq2[s[i-k]-'a']--;
            if(freq1==freq2){
                result.push_back(i-k+1);
            }
        }
        return result;
        
    }
};