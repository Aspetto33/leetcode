// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int result = 0; //��¼����ı���
        int middle = n/2;   //�м�����
        
        //�����Ϊ���εĵ�һ��
        for(int i = 0;i<=middle;i++){
            if(isBadVersion(i) == 1){
                result = i;
                break;
            }
        }

        //���ǰ���û���ҵ�����Ѱ�Һ���һ��
        if(result == 0){
            for(int i = middle+1;i<=n;i++){
                if(isBadVersion(i) == 1){
                    result = i;
                    break;
                }
            }
        }
        return result;
    }
};