class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m=logs.size();
        sort(logs.begin(),logs.end(),[](vector<int>&vec1,vector<int>&vec2){
            return vec1[1]<vec2[1];
        });
       int q=queries.size();
       vector<pair<int,int>>oriIndex(q);
       vector<int>result(q);
       for(int i=0;i<queries.size();i++){
        oriIndex[i]={queries[i],i};
       }
       sort(oriIndex.begin(),oriIndex.end());
       unordered_map<int,int>mp;
       int i=0;
       int j=0;
       for(auto[time,idx]:oriIndex){
        int start= time-x;
        int end= time;
        while(j<m && logs[j][1]<=end){
            mp[logs[j][0]]++;
            j++;
        }
        while(i<m && logs[i][1]<start){
            mp[logs[i][0]]--;
            if(mp[logs[i][0]]==0){
                mp.erase(logs[i][0]);
            }
            i++;
        }
        result[idx]=n- mp.size();

       }
return result;
        
    }
};