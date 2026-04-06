class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best_profit = 0;

        for (int i = 0; i < prices.size(); i++) {
            int purchase = prices[i];
            for (int j = i + 1; j < prices.size(); j++) {
                int sold = prices[j];
                int profit = sold - purchase;
                best_profit = max(best_profit, profit);
            }
        }
        return best_profit;
    }
};

/*
        
profit = sell price - purchase price


brute force:

    for each possible pair of days, calculate profit and keep track of max profit












    //O(n^2)
    //purchase stock in current i index
    //iterate through the rest of the array and calculate curr_profit at each index
    //check if the curr_profit is larger than profit (initially 0)
    //if it is, profit = curr_profit
    //loop finishes 
    //return profit

    //O(n) two pointer approach 
    //iterate and check current profit left = buy/ right sell
    //check if the curr_profit is larger than profit (initially 0)
    //  if it is, update it
    //check if right is smaller (cheaper) than current purhsing price (left)
    //  if it is, move left pointer to right's position

    //FYI: profit = selling price-purchasing price;

    //profi = -3 curr_profit = -3
    //prices = [10,1,5,6,7,1]
    //          i        j

    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int curr_profit = 0; //current profit

        for(int i=0; i<prices.size(); i++){
            //
            for(int j=i+1; j<prices.size(); j++){
                curr_profit = prices[j]-prices[i];
                if(curr_profit > profit){
                    profit = curr_profit;
                }
            }
        

        int left = 0; //buy
        int right = 1; //sell
        while(right < prices.size()){
            curr_profit = prices[right] - prices[left];
            if(curr_profit > profit){
                profit = curr_profit;
            }
            if(prices[right] < prices[left]){
                left = right;
            }
            right++;
        }
        
        return profit;
    }

*/