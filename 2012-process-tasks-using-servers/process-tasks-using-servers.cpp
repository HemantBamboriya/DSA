class Solution {
public:
typedef pair<int,int>p;
typedef tuple<long,int,int>t;
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=servers.size();
        int m=tasks.size();

        priority_queue< p,vector<p>,greater<p>>freeServer;
        priority_queue<t,vector<t>,greater<t>>busyServer;

        for(int i=0;i<n;i++){
            freeServer.push({servers[i],i});//wt,index
        }
        vector<int>result(m);
        for(int i=0;i<m;i++){
            while(!busyServer.empty() && get<0>(busyServer.top())<=i){
                auto [time,wt,index]=busyServer.top();
                busyServer.pop();
                freeServer.push({wt,index});
            }

            if(freeServer.empty()){
                auto [time,wt,index]= busyServer.top();
                busyServer.pop();
                result[i]=index;
                busyServer.push({time+tasks[i],wt,index});
            }else{
                auto[wt,index]=freeServer.top();
                freeServer.pop();
                result[i]=index;
                busyServer.push({tasks[i]+i,wt,index});
            }
        }
return result;
    }
};