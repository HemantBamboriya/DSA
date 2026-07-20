class Solution {
public:
    string capitalizeTitle(string title) {
        int n=(int) title.size();
        int start=0;
        while(start<n){
            while(start<n && title[start]==' '){
                start++;
            }
            if(start>=n){
                break;
            }
            int end=start;
            while(end<n && title[end]!=' '){
                end++;
            }
            if(end-start>2){
                title[start]=toupper(title[start]);
                start++;
                while(start!=end){
                    title[start]=tolower(title[start]);
                    start++;
                }
            }else{
                while(start!=end){
                    title[start]=tolower(title[start]);
                    start++;
                }
            }
            start=end;
        }
      return title;  
    }
};