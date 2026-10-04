class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int index=0;
        int i=0;
        while(i<n){
            int count=0;
            char curr_char=chars[i];
            //count find kar diya char ka
            while(i<n && curr_char==chars[i]){
                count++;
                i++;
            }
            chars[index]=curr_char;
            index++;

//for writing purpose if count>1
           if(count>1){
            string length=to_string(count);
            for(char ch:length){
                chars[index]=ch;
                index++;
            }
           }

        }
        return index;
    }
};