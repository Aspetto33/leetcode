class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];   //��¼����ı�������ʼֵΪ�����һ��Ԫ�ص�ֵ
        int sum = 0;    //��¼����Ԫ�غ͵�ֵ
        for(int i = 0;i< nums.size();i++){
            //��sum>0��ʱ��֤���Լ������¼�����Ԫ��ֵ
            if(sum>0){
                sum+=nums[i];
            //��sum<=0��ʱ���ʱ�϶����������ͣ��������������еĵ�һ��Ԫ��
            }else{
                sum = nums[i];
            }
            result = max(result,sum);   //ÿ�αȽϽ��ϴ�ֵ����result���Ա�֤���ص������ֵ
        }
        return result;
    }
};