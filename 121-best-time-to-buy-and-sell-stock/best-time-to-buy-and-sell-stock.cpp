class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxProfit=0;
        int buy_price=prices[0];
        for(int i=1;i<n;i++){
            buy_price=min(buy_price,prices[i]);
            maxProfit=max(maxProfit,prices[i]-buy_price);
        }
        return maxProfit;
    }
};