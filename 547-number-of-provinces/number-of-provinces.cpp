class Solution {
public:
void bfs(int src,vector<int>adj[],vector<bool>&vis){
    vis[src]=1;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(!vis[it]){
                q.push(it);
                vis[it]=1;
            }
        }
    }

}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        int V=isConnected.size();
        vector<int>adj[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                bfs(i,adj,vis);
                count++;
            }
        }   
        return count;
    }
};