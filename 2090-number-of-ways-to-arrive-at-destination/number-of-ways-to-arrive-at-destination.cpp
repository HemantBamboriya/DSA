class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,long long>>adj[n];
        for(auto it:roads){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        vector<long long>dist(n,1e18);
        vector<int>ways(n);
        ways[0]=1;
        dist[0]=0;
        int mod=1e9+7;
        while(!pq.empty()){
            int node=pq.top().second;
            long long dis=pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                int adjNode=it.first;
                long long adjWt=it.second;
                if(adjWt+dis<dist[adjNode]){
                    dist[adjNode]=adjWt+dis;
                    pq.push({dist[adjNode],adjNode});
                    ways[adjNode]=ways[node];
                }else if(adjWt+dis==dist[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }

            }


        }

      return ways[n-1];  
    }
};