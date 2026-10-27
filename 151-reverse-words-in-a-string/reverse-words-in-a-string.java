class Solution {
    public String reverseWords(String s) {
        StringBuilder sb= new StringBuilder(s);
        sb.reverse();
        int start=0;
        int end=0;
        StringBuilder ans= new StringBuilder();
        int n=s.length();
        while(start<n){
            while(start<n && sb.charAt(start)==' '){
                start++;
            }
            if(start>=n){
               break;
            }
            end=start;
            while(end<n && sb.charAt(end)!=' '){
                end++;
            }
            StringBuilder temp= new StringBuilder();
            for(int i=start;i<end;i++){
                temp.append(sb.charAt(i));
            }
            temp.reverse();
            if(ans.length()>0){
                ans.append(' ');
            }
            ans.append(temp);
            start=end;
            
            
        }
        
       return ans.toString(); 
        
    }
}