class Solution {
public:
    bool isPowerOfTwo(int n) {
        //n����0��ʱ�򲻷�������������false
        if(n == 0) return false;

        //n����1��ʱ���������
        if(n == 1) return true;

        //��n������1��ʱ��ѭ�������n����2��������Ϊ0����ֹѭ��
        while(n!=1){
            if(n%2!=0) break;
            n = n/2;
            // cout<<i;
        }

        if(n!=1) return false;
        return true;
    }
};