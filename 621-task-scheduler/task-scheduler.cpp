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
                int eleFreq= pq.top();
                pq.pop();
                eleFreq--;
                temp.push_back(eleFreq);
            }
        }
        for(int f:temp){
            if(f>0){
                pq.push(f);
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