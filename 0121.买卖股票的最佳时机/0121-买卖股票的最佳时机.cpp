class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = INT_MAX;  //买入股票的最小值
        int result = 0; //结果

        //循环求最大利润
        for(int i = 0;i<prices.size();i++){
            low = min(low,prices[i]);
            result = max(result,prices[i]-low);
        }
        return result;
    }
};