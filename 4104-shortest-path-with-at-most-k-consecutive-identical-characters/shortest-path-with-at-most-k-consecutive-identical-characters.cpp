class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        unordered_map<int,vector<vector<int>>>adj;
        for(auto edge:edges){
            int u= edge[0];
            int v=edge[1];
            int wt= edge[2];

            adj[u].push_back({v,wt});
        }

        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        vector<vector<int>>result(n,vector<int>(k+1,INT_MAX));
        pq.push({0,0,1});
        result[0][1]=0;
        while(!pq.empty()){
            auto[dis,node,count]= pq.top();
            pq.pop();
            if(dis>result[node][count]){
                continue;
            }
            if(node==n-1){
                return dis;
            }

            for(auto & vec:adj[node]){
                int adjNode= vec[0];
                int wt= vec[1];
                int newCount= (labels[adjNode]==labels[node])?count+1:1;
                if(newCount>k){
                    continue;
                }
                int newDist= wt+dis;
                if(newDist<result[adjNode][newCount]){
                    result[adjNode][newCount]=newDist;
                    pq.push({newDist,adjNode,newCount});
                }
            }

        }
        return -1;
    }
};