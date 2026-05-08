class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int bstbuy = prices[0];
        for( int i = 0 ; i < prices.size() ; i++){
            if(prices[i] > bstbuy){
                maxprofit = max(maxprofit , prices[i] - bstbuy);
            }
            bstbuy = min(bstbuy , prices[i]);
        }
        return maxprofit;
         
    }
};