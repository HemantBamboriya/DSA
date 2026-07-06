class Solution {
public:
    string frequencySort(string s) {
        unordered_map<int,int>freq;
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto & it:freq){
            pq.push({it.second,it.first});
        }
        string ans="";
        while(!pq.empty()){
         auto top=pq.top();
         pq.pop();
         int freq=top.first;
         char ch = top.second;
         while(freq>0){
            ans +=  ch;
            freq--;
         }
        }
        return ans;
    }
};