class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //left pointer -> buy
        //right pointer -> sell
        int left = 0;
        int right = 1;
        int maxi = 0;
        int curr_profit = 0;
        while(right < prices.size()){
            curr_profit = prices[right] - prices[left];

            if(prices[left] < prices[right]){
                maxi = max(maxi, curr_profit);
            }
            else{
                left = right;
            }
            right++;
        }
        return maxi;
    }
};