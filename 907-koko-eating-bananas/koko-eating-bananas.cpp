class Solution {
public:

long long countH(vector<int>&piles,int hour){
    long long ans=0;
    for(int i=0;i<piles.size();i++){
        ans += ceil((double)piles[i]/(double)hour);
    }
    return ans;
}


int maxi(vector<int>&piles){
    int maxele=0;
    for(int i=0;i<piles.size();i++){
        maxele=max(maxele,piles[i]);
    }
    return maxele;
}

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=maxi(piles);
        while(low<high){
            int mid=low+(high-low)/2;
            int midE=countH(piles,mid);
            if(midE<=h){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
        
    }
};