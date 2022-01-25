class Solution {
public:
    //����a b
    void swap(char& a,char& b){
        char tmp;   

        tmp = a;
        a = b;
        b = tmp;

    }
    void reverseString(vector<char>& s) {
        
        int leftIndex = 0;  //��ָ��
        int rightIndex = s.size() - 1;  //��ָ��

        //����ָ��С����ָ���ʱ��ѭ����������ָ��ָ���Ԫ��
        while(leftIndex<rightIndex){
            
            swap(s[leftIndex],s[rightIndex]);

            leftIndex++;    //�����ƶ���ָ��
            rightIndex--;   //�����ƶ���ָ��
        }
    }
};