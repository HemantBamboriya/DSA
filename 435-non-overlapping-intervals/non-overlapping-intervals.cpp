class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count=0;
        sort(intervals.begin(),intervals.end(),[](const vector<int>&a,const vector<int>&b){
            return a[1]<b[1];
        });
        int currend=intervals[0][1];
       // int count=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=currend){
                currend=intervals[i][1];
            }else{
                count++;
            }

        }
        return count;
        
    }
};