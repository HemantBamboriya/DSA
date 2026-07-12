class Solution {
public:

vector<int>dijkstra(int vertices,int source,vector<vector<pair<int,int>>>adj){
    vector<int>dist(vertices+1,INT_MAX);
    dist[source]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,source});
    while(!pq.empty()){
        int d=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        if(d>dist[u]) continue;
        for(auto edge:adj[u]){
            int v=edge.first;
            int weight=edge.second;
            if(dist[u] !=INT_MAX && weight+dist[u]<dist[v]){
                dist[v]=weight+dist[u];
                pq.push({dist[v],v});
            }
        }
    }return dist;
}

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto & edge:times){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            adj[u].push_back({v,w});
        }
        vector<int>distance=dijkstra(n,k,adj);
        int maxi=0;
        for(int i=1;i<=n;i++){
            if(distance[i]==INT_MAX){
                return -1;
            }
            maxi=max(maxi,distance[i]);

        }
        return maxi;
    }
};