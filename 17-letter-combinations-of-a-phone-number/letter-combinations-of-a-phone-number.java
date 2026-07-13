class Solution {

    public void solve(int index,StringBuilder temp,String digits,HashMap<Character,String>map,ArrayList<String>result){
        if(index>=digits.length()){
            result.add(temp.toString());
            return;
        }
        char ch=digits.charAt(index);
        String letter=map.get(ch);

        for(int i=0;i<letter.length();i++){
            temp.append(letter.charAt(i));
            solve(index+1,temp,digits,map,result);
            temp.deleteCharAt(temp.length()-1);
        }

    }
    public List<String> letterCombinations(String digits) {
        ArrayList<String>result=new ArrayList<>();
        StringBuilder temp= new StringBuilder();
        if(digits.length()==0){
            return result;
        }
        HashMap<Character,String>map=new HashMap<>();
        map.put('2',"abc");
        map.put('3',"def");
        map.put('4',"ghi");
        map.put('5',"jkl");
        map.put('6',"mno");
        map.put('7',"pqrs");
        map.put('8',"tuv");
        map.put('9',"wxyz");
        solve(0,temp,digits,map,result);
        return result;
        
    }
}