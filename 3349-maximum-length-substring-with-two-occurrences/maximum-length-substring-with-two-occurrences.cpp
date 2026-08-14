class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxlength=INT_MIN;
        unordered_map<char,int>freq;
        int left=0;
        for(int right=0;right<s.length();right++){
            freq[s[right]]++;
                while(freq[s[right]]>2){
                    freq[s[left]]--;
                    left++;
                }
                maxlength=max(maxlength,right-left+1);
            }
        return maxlength;
        
    }
};