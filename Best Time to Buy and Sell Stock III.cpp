//当与2相关时，第一反应：二分法，切片
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
            return 0;
            
        //find the proMax
        int min = 0 , N = prices.size();
        int preMax[N];
        preMax[0] = 0;
        for(int i = 1;i<prices.size();i++)
        {
            min = (prices[i]<prices[min])?i:min;
            preMax[i] = ((prices[i]-prices[min])>preMax[i-1])?(prices[i]-prices[min]):preMax[i-1];
            cout<<preMax[i];
        }
        
        //find the latter max
        int max = N-1 ,latterMax[N];
        latterMax[N-1] = 0;
        for(int i = N-2;i>=0;i--)
        {
            max = (prices[i]>prices[max])?i:max;
            latterMax[i] = ((prices[max]-prices[i])>latterMax[i+1])?(prices[max]-prices[i]):latterMax[i+1];
        }
        
        //compute the max value of two trans
        int maxPro = preMax[N-1];
        //***VI:advoid the solution: keeping increasing!
        
        for(int i = 0 ;i < N-1;i++)
        {
            if(preMax[i]+latterMax[i]>maxPro)
                maxPro = preMax[i]+latterMax[i+1];
        }
        
        return maxPro;
    }
};
