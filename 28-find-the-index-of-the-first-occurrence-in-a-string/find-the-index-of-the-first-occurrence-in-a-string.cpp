class Solution {
public:
    int strStr(string haystack, string needle) {
        int ind= haystack.find(needle);
        if(ind==string::npos){
            return -1;
        }else{
            return ind;
        }
        
    }
};