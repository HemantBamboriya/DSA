class Solution {
public:
    bool equalFrequency(string word) {
        
        for(int i=0;i<word.size();i++){
         vector<int>freq(26,0);
         for(int j=0;j<word.size();j++){
            if(i!=j){
                freq[word[j]-'a']++;
            }
         }
         int f=0;
         bool ok=true;

         for(int x:freq){
            if(x==0) continue;
            if(f==0){
                f=x;
            }else if(f!=x){
                ok=false;
                break;
            }
         }
         if(ok){
            return true;
         }
        }
        return false;
    }
};