//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
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

//Solution II
//Judge prices[i]-prices[i-1]>0 or <0
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
            return 0;
        int maxPro =0,diff=0;
        for(int i=1;i<prices.size();i++)
        {
            diff = prices[i]-prices[i-1];
            if(diff>0)
                maxPro += diff;
        }
        return maxPro;
    }
};
