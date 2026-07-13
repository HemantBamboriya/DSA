class Solution {
public int findGCD(int a,int b){
    if(b==0) return a;
    return findGCD(b,a%b);
}

    public String gcdOfStrings(String str1, String str2) {
        if(!(str1+str2).equals(str2+str1)){
            return "";
        }
        int len=findGCD(str1.length(),str2.length());
        return str1.substring(0,len);
        
    }
}