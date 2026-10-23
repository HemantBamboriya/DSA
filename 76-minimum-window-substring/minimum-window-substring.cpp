class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(m>n){
            return "";
        }
        unordered_map<char,int>freq;
        for(char ch:t){
            freq[ch]++;
        }
        int left=0;
        int start=0;
        int maxLength=INT_MAX;
        int count=0;
        for(int right=0;right<n;right++){
            if(freq[s[right]]>0){
                count++;
            }
            freq[s[right]]--;
            while(count==m){
                if(right-left+1<maxLength){
                    maxLength= right-left+1;
                    start=left;
                }
                freq[s[left]]++;
                if(freq[s[left]]>0){
                    count--;
                }
                left++;
            }
        }
    if(maxLength==INT_MAX){
        return "";
    }
    return s.substr(start,maxLength);

        
    }
};