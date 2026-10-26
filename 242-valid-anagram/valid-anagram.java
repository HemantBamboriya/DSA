class Solution {
    public boolean isAnagram(String s, String t) {
        int n=s.length();
        int m=t.length();
        if(m!=n){
            return false;
        }
        HashMap<Character,Integer>mp= new HashMap<>();
        for(int i=0;i<n;i++){
            mp.put(s.charAt(i),mp.getOrDefault(s.charAt(i),0)+1);
        }
        for(int i=0;i<m;i++){
            if(mp.containsKey(t.charAt(i))){
                int freq= mp.get(t.charAt(i));
                freq--;
                if(freq<0){
                    return false;
                }
                mp.put(t.charAt(i),freq);

            }else{
                return false;
            }

        }
        return true;
        
    }
}