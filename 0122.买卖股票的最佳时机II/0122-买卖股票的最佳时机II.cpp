class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0; //��¼���ս��
        //�ӵڶ���Ԫ�ؿ�ʼ���ú�һ��Ԫ�ؼ�ȥǰһ��Ԫ��
        for(int i=1;i<prices.size();i++){
            result+= max((prices[i]-prices[i-1]),0);    //ֻ�Ӵ�����Ĳ�ֵ
        }
        return result;
    }
};