class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;
        int maxwater=INT_MIN;
        while(left<right){
            int length=min(height[left],height[right]);
            int width=right-left;
            maxwater=max(maxwater,length*width);
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxwater;
    }
};