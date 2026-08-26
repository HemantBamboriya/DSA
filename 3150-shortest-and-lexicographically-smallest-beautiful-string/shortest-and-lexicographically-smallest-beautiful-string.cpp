class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
       int totalCount=0;
       for(int i=0;i<s.length();i++){
        if(s[i]=='1'){
            totalCount++;
        }
       }
       if(totalCount<k){
        return "";
       }
       int count=0;
       int left=0;
       int startIndex=-1;
       int length=INT_MAX;
       string ans="";
       for(int i=0;i<s.length();i++){
        if(s[i]=='1'){
            count++;
        }
        while(count>k){
            if(s[left]=='1'){
                count--;
            }
            left++;
        }
        while(count==k ){
           if(i-left+1<length ){
            length=i-left+1;
            startIndex=left;
            ans=s.substr(startIndex,length);
           }else if(i-left+1==length){
             string curr=s.substr(left,i-left+1);
             if(curr<ans){
                ans=curr;
             }
           }

            if(s[left]=='1'){
            count--;
            }
            left++;
        }
       }
return ans;
        
    }
};