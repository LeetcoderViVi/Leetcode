class Solution {
public:
    int maxProfit(vector<int>& prices) {
		if(prices.size()==0||prices.size()==1)
			return 0;
        int min=0,maxprofit=0,profit=0;
		for(int i=0;i<prices.size();i++)
		{
			if(prices[i]<prices[min])
				min = i;
			if(prices[i]-prices[min]>profit)
				profit = prices[i] - prices[min];
			//consider the another profit again.
			if(prices[i]-prices[min]<profit)
			{
				min = i;
				maxprofit += profit;
				profit = 0;
			}
		}
		if(profit!=0)
			maxprofit+=profit;
		return maxprofit;
    }
};
