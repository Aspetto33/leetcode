class Solution {
public:
    //��������
    void swap(char& a,char& b){
        char tmp;

        tmp = a;
        a = b;
        b = tmp;
    }
    string reverseWords(string s) {
        int slowIndex = 0;  //��ָ��
        int fastIndex = 0;  //��ָ��

        //����ѭ�������ǿ�ָ�벻����s�ĳ���
        while(fastIndex<s.size()){

            //�ƶ���ָ�뵽���ʵĿո�
            while(fastIndex<s.size()&&s[fastIndex]!=' '){
                fastIndex++;
            }

            int fastIndex1 = fastIndex - 1; //����β��

            //��ת����
            while(slowIndex<fastIndex1){
                swap(s[slowIndex],s[fastIndex1]);
                slowIndex++;
                fastIndex1--;
            }
            fastIndex++;    //��ָ�뵽�¸����ʵ�ͷ��

            //�ƶ���ָ�뵽�¸����ʵ�ͷ��
            while(slowIndex<s.size()&&s[slowIndex]!=' '){
                slowIndex++;
            }
            slowIndex++;
        }
        return s;
    }
};