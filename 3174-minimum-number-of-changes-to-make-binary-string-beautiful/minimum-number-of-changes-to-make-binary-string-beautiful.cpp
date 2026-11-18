class Solution {
public:
    int minChanges(string s) {
        int n=s.size();
        int curr_char=s[0];
        int count=0;
        int changes=0;

        for(int i=0;i<n;i++){
            if(s[i]==curr_char){
                count++;
                continue;
            }

            if(count%2==0){
                count=1;
            }else{
                changes +=1;
                count=0;
            }

     
            curr_char=s[i];

        }
        return changes;
    }
};