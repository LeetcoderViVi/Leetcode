class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=0,maxprofit=0;
        for(int i=1;i<prices.size();i++)
        {
        	if(prices[i]<prices[min])
        		min = i;
        	if(prices[i]-prices[min]>maxprofit)
        		maxprofit = prices[i]-prices[min];
        }
        return maxprofit;
    }
};
