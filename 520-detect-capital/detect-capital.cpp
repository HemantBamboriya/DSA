class Solution {
public:
    bool detectCapitalUse(string word) {
        
        string alllower=word;
         transform(alllower.begin(),alllower.end(),alllower.begin(),::tolower);
        string allupper=word;
         transform(allupper.begin(),allupper.end(),allupper.begin(),::toupper);
        string onlyfirstupper="";
        for(int i=0;i<word.length();i++){
            if(i==0){
                onlyfirstupper += (toupper(word[i]));
            }else{
                onlyfirstupper += tolower(word[i]);
            }
        }
        if(alllower==word || allupper==word || onlyfirstupper==word){
            return true;
        }
        return false;        
    }
};