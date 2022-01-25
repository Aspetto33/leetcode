class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int result = 0; //��¼���
        int minPrice = prices[0];   //��������Сֵ����ֵ

        for(int i =1;i<prices.size();i++){
            //��Ʊ��Сֵ��ʱ������
            if(prices[i]<minPrice) minPrice = prices[i];

            //��ǰ�۸������С����۸���ͬʱ������ʱ������֧���ɱ�������ԭ��
            if(prices[i]>=minPrice&&prices[i]<=minPrice+fee){
                continue;
            }

            //��ǰ��Ʊ�۸���ڳɱ�ʱ�������ջ����󣬵���һ������������
            if(prices[i]>minPrice+fee){
                result+=prices[i] - minPrice - fee;
                minPrice = prices[i] - fee;
            }
        }
        return result;
    }
};