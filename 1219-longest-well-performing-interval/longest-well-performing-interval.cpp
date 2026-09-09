class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int count=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        int length=0;
        for(int i=0;i<hours.size();i++){
            if(hours[i]>8){
                count +=1;
            }else{
                count -=1;
            }
          if(count>0){
            length=max(length,i+1);
            continue;
          }else{
            if(!mp.count(count)){
                mp[count]=i;
            }

            if(mp.count(count-1)){
                length=max(length,i-mp[count-1]);
            }
          }
        }
        return length;
        
    }
};