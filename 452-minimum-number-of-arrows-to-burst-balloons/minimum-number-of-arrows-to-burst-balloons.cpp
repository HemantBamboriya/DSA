class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        sort(points.begin(),points.end(),[](const vector<int>&a1,const vector<int>&a2){
            return a1[1]<a2[1];
        });
        int arrows=1;
        int currend=points[0][1];
        for(int i=1;i<points.size();i++){
          if(points[i][0]>currend){
            currend=points[i][1];
            arrows++;
          }
        }
        return arrows;
    }
};