class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = INT_MAX;  //�����Ʊ����Сֵ
        int result = 0; //���

        //ѭ�����������
        for(int i = 0;i<prices.size();i++){
            low = min(low,prices[i]);
            result = max(result,prices[i]-low);
        }
        return result;
    }
};