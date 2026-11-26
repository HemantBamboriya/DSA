class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length==0){
            return 0;
        }
        HashSet<Integer>st= new HashSet<>();
        for(int num:nums){
            st.add(num);
        }
int count=1;
        for(int num:st){
           int curr=num;
           int curr_count=1;
           if(!st.contains(curr-1)) {
            while(st.contains(curr+1)){
                curr +=1;
                curr_count +=1;
            }
            count=Math.max(count,curr_count);

        }
     
        
    }
    return count;
}
}