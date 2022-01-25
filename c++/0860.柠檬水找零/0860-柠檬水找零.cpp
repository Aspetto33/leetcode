class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0]>5){
            return false;
        }else{
            int record5 = 0;    //��¼���е�5Ԫ������
            int record10 = 0;   //��¼���е�10Ԫ������
            int record20 = 0;   //��¼���е�20Ԫ������

            //ѭ���������飬�ж�����Ƿ���ȫ���ɹ�����
            for(int i=0;i<bills.size();i++){

                //������Ǯ��5Ԫʱ��record5��1����ʱ��������
                if(bills[i] == 5){
                    record5++;
                }

                //������Ǯ��10Ԫʱ���ж�5Ԫ��������������ڵ���1����record5��1��record10��1
                //���򷵻�false
                if(bills[i] == 10){
                    if(record5>=1){
                        record10++;
                        record5--;
                    }else{
                        return false;
                    }
                }

                //������Ǯ��20ʱ�������ж��Ƿ��д���0�ŵ�10Ԫ��5Ԫ����Ϊ10Ԫֻ�ܸ�20��
                //�������record10��record5��1��record20��1
                //������������ϵ�5Ԫʱ����record5-3��record20��1
                //���򷵻�false
                if(bills[i]==20){
                   if(record5>0&&record10>0){
                       record5--;
                       record10--;
                       record20++;
                   }else if(record5>=3){
                       record5-=3;
                       record20++;
                   }else{
                       return false;
                   }
                }
            }
        }
        return true;
    }
};