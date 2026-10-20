class Solution {
public:
    int strStr(string haystack, string needle) {
       int n=haystack.length();
       int m=needle.length();

       vector<int>LPS(m,0);
       int length=0;
       int i=1;
       LPS[0]=0;

       while(i<m){
        if(needle[i]==needle[length]){
            length++;
            LPS[i]=length;
            i++;
        }else{
            if(length!=0){
                length= LPS[length-1];
            }else{
                i++;
            }
        }
       }

       i=0;
       int j=0;
       while(i<n){
        if(haystack[i]==needle[j]){
            i++;
            j++;

             if(j==m){
           return i-j;
        }

       
        }else{
            if(j!=0){
                j=LPS[j-1];
            }else{
                i++;
            }

        }
       }


        return -1;
    }
};