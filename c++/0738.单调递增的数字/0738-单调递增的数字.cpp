class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string str_n = to_string(n);    //������ת��Ϊ�ַ���
        //flag�ĳ�ʼֵҪΪ�ַ�����С����Ϊ����������ֱ������ǵ����Ļ���
        //���ñ�9��ֱ�ӷ���ԭֵ����
        int flag = str_n.size();    
        //�Ӻ���ǰ����
        for(int i = str_n.size()-1; i>0;i--){
            if(str_n[i-1]>str_n[i]){
                flag = i;
                str_n[i-1]--;
            }
        }
        for(int i = flag;i<str_n.size();i++){
            str_n[i] = '9';
        }
        return stoi(str_n);
    }
};