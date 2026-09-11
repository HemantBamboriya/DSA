class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int>freq(10,0);
        for(int dig:digits){
            freq[dig]++;
        }
        int ans=0;
        for(int i=1;i<=9;i++){
            for(int j=0;j<=9;j++){
                for(int k=0;k<=8;k+=2){
                    vector<int>temp(freq.begin(),freq.end());
                    if(temp[i]==0){
                        continue;
                    }
                    temp[i]--;
                    if(temp[j]==0){
                        continue;
                    }
                    temp[j]--;
                    if(temp[k]==0){
                        continue;
                    }
                    ans++;
                }
            }
        }
        return ans;
    }
};