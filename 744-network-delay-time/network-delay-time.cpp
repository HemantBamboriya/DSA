class Solution {
public:
vector<int>dijsktra(int n,int src,vector<pair<int,int>>adj[]){
    priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src});//dist,node;
    vector<int>dist(n+1,1e9);
    dist[src]=0;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int node=it.second;
        int dis=it.first;
        if(dis>dist[node]) continue;
        for(auto it:adj[node]){
            int adjNode=it.first;
            int adjWt=it.second;
            if(adjWt+dis<dist[adjNode]){
                dist[adjNode]=adjWt+dis;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        int res=0;
        vector<int>ans=dijsktra(n,k,adj);
        for(int i=1;i<ans.size();i++){
            if(ans[i]==1e9){
                return -1;
            }
            res=max(ans[i],res);
        }
        return res;
    }
};