class Solution {
public:
void merge(vector<int>&nums,int si,int ei,int mid){
    int i=si;
    int j=mid+1;
    vector<int>temp;
    while(i<=mid && j<=ei){
        if(nums[i]<=nums[j]){
            temp.push_back(nums[i++]);
        }else{
            temp.push_back(nums[j++]);
        }
    }
    while(i<=mid){
        temp.push_back(nums[i++]);
    }
    while(j<=ei){
        temp.push_back(nums[j++]);
    }
    for(int i=si;i<=ei;i++){
        nums[i]=temp[i-si];
    }
}

int countPairs(vector<int>&nums,int si,int ei,int mid){
    int right=mid+1;
    int count=0;
    for(int low=si;low<=mid;low++){
        while(right<=ei && nums[low]>2LL*nums[right]){
            right++;
        }
        count= count+ (right-(mid+1));

    }
    return count;
}


int mergeSort(vector<int>&nums,int si,int ei){
    int count=0;
    if(si>=ei) return count;
    int mid=si+(ei-si)/2;
   count+= mergeSort(nums,si,mid);
    count+= mergeSort(nums,mid+1,ei);
    count += countPairs(nums,si,ei,mid);
    merge(nums,si,ei,mid);
    return count;

}

    int reversePairs(vector<int>& nums) {
        int n=nums.size();
       return mergeSort(nums,0,n-1);

        
    }
};