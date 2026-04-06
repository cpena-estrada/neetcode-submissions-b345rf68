class Solution {
public:

    //purchase stock in current i index
    //iterate through the rest of the array and calculate curr_profit at each index
    //check if the curr_profit is larger than profit (initially 0)
    //if it is, profit = curr_profit
    //loop finishes 
    //return profit

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
        }
        return profit;
    }
};
