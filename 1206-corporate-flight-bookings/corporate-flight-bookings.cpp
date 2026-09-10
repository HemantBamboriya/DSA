class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>diff(n+2,0);
        for(int i=0;i<bookings.size();i++){
            int start=bookings[i][0];
            int end=bookings[i][1];
            diff[start] += bookings[i][2];
            diff[end+1]-= bookings[i][2];
        }
        vector<int>ans(n);
        for(int i=1;i<=n;i++){
            diff[i] += diff[i-1];
            ans[i-1]=diff[i];
        }
        return ans;
    }
};