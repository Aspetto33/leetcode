class Solution {
public:
    int numSquares(int n) {
        //���������¼��ƽ����������n�����ƽ����ҲҪpush��ȥ
        vector<int> nums;
        for(int i = 0;i<=n;i++){
            if(sqrt(i)-(int)sqrt(i)==0){
                nums.push_back(i);
            }
        }

        //��ʹ�����ٵ�ƽ�������Ҫ���������˳�ʼֵҪ�����ֵ��ֹ������
        vector<int> dp(n+1,INT_MAX);
        //��ɺ�Ϊ0�õ�0��ƽ����
        dp[0] = 0;
        //��ϲ������У������˳���޹أ�ƽ��������ʹ�ã��������ȫ�������⣬������С�������
        for(int i = 0;i<nums.size();i++){
            for(int j = nums[i];j<=n;j++){
                if(dp[j-nums[i]]!=INT_MAX){
                    dp[j] = min(dp[j],dp[j-nums[i]]+1);
                }
                
            }
        }
        return dp[n];
    }
};