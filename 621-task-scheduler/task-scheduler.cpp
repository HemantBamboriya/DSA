class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
        }
        priority_queue<int>pq;
      for(int i=0;i<26;i++){
        if(freq[i]>0){
            pq.push(freq[i]);
        }
      }
      int timer=0;
      while(!pq.empty()){
        vector<int>temp;
        for(int i=1;i<=n+1;i++){
            if(!pq.empty()){
                int ele=pq.top();
                pq.pop();
                ele--;
                temp.push_back(ele);
            }
        }
        for(int num:temp){
            if(num>0){
                pq.push(num);
            }
        }
        if(pq.empty()){
            timer += temp.size();
        }else{
            timer += n+1;
        }


      }
return timer;
        
    }
};