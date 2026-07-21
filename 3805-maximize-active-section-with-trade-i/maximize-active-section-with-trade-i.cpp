class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int totalOne=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                totalOne++;
            }
        }
        s.insert(s.begin(),'1');
        s.push_back('1');
        vector<pair<char,int>>rle;
        int n=s.length();

        char curr=s[0];
        int count=1;
        for(int i=1;i<n;i++){
            if(s[i]==curr){
                count++;
            }else{
                rle.push_back({curr,count});
                curr=s[i];
                count=1;
            }
          
        }
          rle.push_back({curr,count});   
        int ans=totalOne;
        for(int i=1;i<rle.size()-1;i++){
            if(rle[i].first=='1' && rle[i-1].first=='0' && rle[i+1].first=='0'){
                ans=max(ans,totalOne+rle[i-1].second+rle[i+1].second);
            }
        }
        return ans;
    }
};