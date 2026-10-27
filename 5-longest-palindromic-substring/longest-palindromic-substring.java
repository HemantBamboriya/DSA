class Solution {
 public static boolean isPalindrome(int i,int j,String s,int [][]dp){
  if(i>=j){
    return true;
  }

  if(dp[i][j]!=-1){
    return dp[i][j]==1;
      }
  if(s.charAt(i)==s.charAt(j)){
    boolean result= isPalindrome(i+1,j-1,s,dp);
    dp[i][j]= result?1:0;
    return result;
  }
  dp[i][j]=0;
  return false;
 }


    public String longestPalindrome(String s) {
        int n=s.length();
        int [][]dp= new int[n][n];
        for(int [] row:dp){
            Arrays.fill(row,-1);
        }
        int startIndex=0;
        int length=-1;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s,dp)==true){
                    if(j-i+1>length){
                        length= j-i+1;
                        startIndex=i;
                    }
                }
            }
        }
        return s.substring(startIndex,startIndex+length);
    }
}