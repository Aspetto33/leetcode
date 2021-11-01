class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int result = 0; //记录结果
        int minPrice = prices[0];   //给买入最小值赋初值

        for(int i =1;i<prices.size();i++){
            //股票最小值的时候买入
            if(prices[i]<minPrice) minPrice = prices[i];

            //当前价格大于最小买入价格并且同时卖出的时候不足以支付成本，保持原样
            if(prices[i]>=minPrice&&prices[i]<=minPrice+fee){
                continue;
            }

            //当前股票价格大于成本时，可以收获利润，但不一定是最后的卖出
            if(prices[i]>minPrice+fee){
                result+=prices[i] - minPrice - fee;
                minPrice = prices[i] - fee;
            }
        }
        return result;
    }
};