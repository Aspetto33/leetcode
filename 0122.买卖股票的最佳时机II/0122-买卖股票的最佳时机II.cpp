class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0; //记录最终结果
        //从第二个元素开始，用后一个元素减去前一个元素
        for(int i=1;i<prices.size();i++){
            result+= max((prices[i]-prices[i-1]),0);    //只加大于零的差值
        }
        return result;
    }
};