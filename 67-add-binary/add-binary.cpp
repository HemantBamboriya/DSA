class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.length()-1;
        int m=b.length()-1;
        int sum=0;
        int carry=0;
        string result="";

        while(n>=0 || m>=0){
            sum=carry;
            if(n>=0){
                sum += a[n]-'0';
                n--;
            }
            if(m>=0){
                sum += b[m]-'0';
                m--;
            }
            result.push_back(sum%2==0?'0':'1');
            carry=(sum>1)?1:0;
        }
        if(carry){
            result.push_back('1');
        }
        reverse(result.begin(),result.end());
        return result;
  
    }
};