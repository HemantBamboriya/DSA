class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int ans=INT_MIN;
        while(left<right){
             int heigh=min(height[left],height[right]);
             int width=right-left;
                ans = max(ans,heigh*width);
                if(height[left]<height[right]){
                    left++;
                }else{
                    right--;
                }
        }
        return ans;
    }
};