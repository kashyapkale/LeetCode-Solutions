class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int nextMax = INT_MIN;
        int maxProfit = INT_MIN;
        int N = prices.size();
        for(int i=N-1;i>=0;i--){
            nextMax = max(nextMax,prices[i]);
            maxProfit = max(maxProfit,nextMax-prices[i]);
        }
        return maxProfit;
    }
};