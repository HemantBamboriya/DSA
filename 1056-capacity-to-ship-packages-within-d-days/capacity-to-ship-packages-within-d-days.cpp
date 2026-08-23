class Solution {
public:
int findDays(int Mday,vector<int>&weights){
    int n=weights.size();
    int day=1;
    int load=0;
    for(int i=0;i<n;i++){
        if(load+weights[i]>Mday){
            day +=1;
            load=weights[i];
        }else{
            load += weights[i];
        }
    }
    return day;
}


    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=INT_MIN;
        for(int i=0;i<weights.size();i++){
            maxi=max(maxi,weights[i]);
        }
        int high=0;
        for(int i=0;i<weights.size();i++){
            high += weights[i];
        }
        int low=maxi;
        while(low<high){
            int mid=low+(high-low)/2;
            if(findDays(mid,weights)<=days){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
        
    }
};