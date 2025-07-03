/* Stock Buy and Sell – Max one Transaction Allowed :
Given an array prices[] of length n, representing the prices of the stocks on different days. 
The task is to find the maximum profit possible by buying and selling the stocks on different days when at most one transaction is allowed. 
Here one transaction means 1 buy + 1 Sell. If it is not possible to make a profit then return 0.

Note: Stock must be bought before being sold. */


class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int minPrice = INT_MAX;
        int maxProfit = 0;
        
        for(int price : prices){
            minPrice = min(minPrice, price);                // Best day to buy so far
            maxProfit = max(maxProfit, price-minPrice);    //  Best profit if sold today
        }
        
        return maxProfit;
    }
};
