class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
      vector<bool> vec(101, false);

        for (int x : nums) {
            vec[x] = true;
        }

        int num = k;

        while (num <= 100 && vec[num]) {
            num += k;
        }

        return num;
    }
};