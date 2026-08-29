class Solution {
public:

int lowerBound(vector<int>&nums,int target){
    int n=nums.size();
    int ans=n;
    int st=0;
    int end=n-1;
    while(st<=end){
        int mid= st+(end-st)/2;
        if(nums[mid]>=target){
            ans=mid;
            end=mid-1;
        }else{
            st=mid+1;
        }
    }
    return ans;
}
int upperBound(vector<int>&nums,int target){
    int n=nums.size();
    int ans=n;
    int st=0;
    int end=n-1;
    while(st<=end){
        int mid= st+(end-st)/2;
        if(nums[mid]>target){
            ans=mid;
            end=mid-1;
        }else{
            st=mid+1;
        }
    }
    return ans;

}

    vector<int> searchRange(vector<int>& nums, int target) {
        int first=lowerBound(nums,target);
        int last=upperBound(nums,target);
        if(first==nums.size() || nums[first]!=target){
            return {-1,-1};
        }
        return {first,last-1};

        
    }
};