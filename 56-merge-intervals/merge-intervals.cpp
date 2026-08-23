class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        if(intervals.size()==1) return intervals;
       ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(ans.back()[1]<intervals[i][0]){
                ans.push_back(intervals[i]);
            }else{
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }


        }
        return ans;
        
    }
};