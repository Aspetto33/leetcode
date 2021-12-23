class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int result = 0;
        int minNum = prices[0];

        for(int i = 1;i<prices.size();i++){
            result = max(result,prices[i] - minNum);

            if(prices[i]<minNum) minNum = prices[i];
        }
        return result;
    }
};