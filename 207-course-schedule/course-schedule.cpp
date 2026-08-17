class Solution {
public:
bool dfs(int node,vector<int>&visited,vector<int>&pathVis,vector<vector<int>>&prerequisites){
    visited[node]=1;
    pathVis[node]=1;
    for(auto it:prerequisites[node]){
        if(!visited[it]){
            if(dfs(it,visited,pathVis,prerequisites)==true){
                return true;
            }
        }else if(pathVis[it]){
            return true;
        }
    }
    pathVis[node]=0;
    return false;
}

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>visited(numCourses,0);
        vector<int>pathVis(numCourses,0);
        vector<vector<int>>graph(numCourses);
        for(auto p:prerequisites){
            graph[p[1]].push_back(p[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(i,visited,pathVis,graph)==true){
                    return false;
                }
            }
        }

        return true;
    }
};