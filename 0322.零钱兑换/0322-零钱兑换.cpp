class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //��ʼ����¼���飬dp[j]��ʾ�ﵽj��Ҫʹ�õ�����Ӳ����,
        vector<int> dp(amount+1,INT_MAX);   //��Ϊ������Сֵ����˳�ʼ��Ҫ�����ֵ���Է�������

        //dp[0]����˼�Ǵ���0�����Ҫ������Ӳ��������0
        dp[0] = 0;

        //�޹�˳��
        for(int i = 0;i<coins.size();i++){
            for(int j = coins[i];j<=amount;j++){
                if(dp[j-coins[i]]!=INT_MAX){
                    dp[j] = min(dp[j],dp[j-coins[i]]+1);    //����ǳ�ʼֵ������
                }
                
            }
        }
        if(dp[amount] == INT_MAX) return -1;
        return dp[amount]; 
    }
};