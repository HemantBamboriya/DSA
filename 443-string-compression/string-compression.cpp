class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int index=0;//for writing purpose in original vector
        int i=0;//curr index
        while(i<n){
            //curr char to count freq
            char curr_char=chars[i];
            int count=0;
            //calculate freq if appear then more than 1 time
            while(i<n && curr_char==chars[i]){
                count++;
                i++;
            }
            //to write in chars vector
            chars[index]=curr_char;
            index++;
           //if count>1 the only need to write the count otherwise we can go further
            if(count>1){
                //convert it in string beacause if length is greater than 9 then two saprate digits are required
                string length= to_string(count);
                for(char ch:length){
                    chars[index]=ch;
                    index++;
                }
            }
        }
        //return the curr index because this is the answer 
        return index;
    }
};