class Solution {
public:

int getTotalSum(int num){
    int sum=0;
    while(num>0){
        sum += num%10;
        num /= 10;
    }
    return sum;
}
    int minSwaps(vector<int>& nums) {

        int n = nums.size();
        vector<int> afterSorted(nums);

        auto lambda = [this](int num1, int num2) {
                int totalNum1Sum = getTotalSum(num1);
                int totalNum2Sum = getTotalSum(num2);

                if (totalNum1Sum != totalNum2Sum) {
                    return totalNum1Sum < totalNum2Sum;
                }
                return num1 < num2;
            };

        sort(afterSorted.begin(), afterSorted.end(), lambda);

        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }

        int swapCount=0;
        for(int i=0;i<nums.size();i++){
            int expected= afterSorted[i];
            int curr= nums[i];
            if(expected==curr){
                continue;
            }
            swapCount++;
            int index= mp[expected];
            nums[i]=expected;
            nums[index]=curr;

            mp[expected]=i;
            mp[curr]=index;
        }
        return swapCount;
    }
};