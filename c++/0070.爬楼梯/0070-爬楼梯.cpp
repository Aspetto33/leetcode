/*
 *������Ŀ�Ƶ��ó���ǰ���������ߵ�ѡ������ǰ������ѡ������ӣ���3��ʼ��ѭ�˹���
 *���dp[i]������˼����i��¥�ݣ��ж���ѡ��
*/
class Solution {
public:
    int climbStairs(int n) {
        //��nΪ0��ʱ��ֱ�ӷ���n����
        if(n<=1){
            return n;
        }
        vector<int> dp(n+1);
        dp[1]=1;
        dp[2]=2;
        //���ɴ�3��ʼ
        for(int i=3;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];   
    }
};