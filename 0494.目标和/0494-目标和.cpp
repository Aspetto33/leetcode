/*
 *����ӷ����ܺ���x����������ܺ�������Ԫ���ܺ�sum-x��
 *��ӷ��ͼ�ȥ�����ĺ�Ӧ�õ���Ŀ��ֵ����x-��sum-x��=target
 *���Ե��ӷ��ܺ͵��ڣ�sum+target��/2ʱ��ǡ���ܴﵽtarget
 *��ʱӦ�����ж����ַ������Դﵽ��������Ϊx�ı���
*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i = 0;i<nums.size();i++) sum+=nums[i];

        //������ߵĺͲ���ż���Ļ����Ǵﲻ��Ҫ��ģ���Ϊ����Ԫ�ض�������
        if((sum+target)%2==1) return 0;
        
        //���Ŀ��ֵ��������Ԫ���ܺͣ�ͬ���ﲻ��
        if(abs(target)>sum) return 0;

        //�ӷ��ܺͣ�����������ΪbigSize�ı���
        int bigSize = (sum+target)/2;

        vector<int> dp(bigSize+1,0);
        dp[0] = 1;  //װ������Ϊ0�ı�����1�ַ�������ʲôҲ��װ

        for(int i = 0;i<nums.size();i++){
            for(int j = bigSize;j>=nums[i];j--){
                dp[j]+=dp[j-nums[i]];   //���ƹ�ʽ��ֵ�ۼ�
            }
        }
        return dp[bigSize];
    }
};