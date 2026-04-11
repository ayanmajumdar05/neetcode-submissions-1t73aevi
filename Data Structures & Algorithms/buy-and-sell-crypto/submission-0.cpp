class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 0;
        int profit = 0;

        while(r<prices.size())
        {
            if(prices[l] < prices[r]) // positive profit case
            {
                int currentProfit = prices[r] - prices[l];
                profit = max(currentProfit,profit);
            }
            else
            {
                l = r;
            }
            r++;
        }
        return profit;
    }
};
