class Solution {
    public int subarrayBitwiseORs(int[] arr) {
        HashSet<Integer>prev=new HashSet<>();
        
        HashSet<Integer>result=new HashSet<>();
        for(int i=0;i<arr.length;i++){
            HashSet<Integer>curr=new HashSet<>();
            for(int num:prev){
                curr.add(arr[i]|num);
                result.add(arr[i]|num);
            }
            curr.add(arr[i]);
            result.add(arr[i]);
            prev=curr;
            
        }
        
    
    return result.size();
    }
}