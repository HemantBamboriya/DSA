class Solution {
public:
void merge(vector<pair<int,int>>&arr,int si,int ei,int mid,vector<int>&ans){
    int i=si;
    int j=mid+1;
    vector<pair<int,int>>temp;
    while(i<=mid && j<=ei){
        if(arr[i].first<=arr[j].first){
            ans[arr[i].second] += j-(mid+1);
            temp.push_back(arr[i++]);
        }else{
            temp.push_back(arr[j++]);
        }
    }
    while(i<=mid){
        ans[arr[i].second] += j-(mid+1);
        temp.push_back(arr[i++]);
    }
    while(j<=ei){
        temp.push_back(arr[j++]);
    }

    for(int i=si;i<=ei;i++){
        arr[i]=temp[i-si];
    }
}

void mergeSort(vector<pair<int,int>>&arr,int si,int ei,vector<int>&ans){
    if(si>=ei) return ;
    int mid=si+(ei-si)/2;
    mergeSort(arr,si,mid,ans);
    mergeSort(arr,mid+1,ei,ans);
    merge(arr,si,ei,mid,ans);
}

    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        vector<int>ans(n,0);
        mergeSort(arr,0,n-1,ans);
        return ans;
        
    }
};