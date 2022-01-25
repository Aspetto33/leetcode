class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result; //���ս������

        int startIndex = 0; //ͷָ��
        int endIndex = numbers.size() - 1;  //βָ��

        for(int i = 0;i<numbers.size();i++){

            //���ͷβָ��ָ���Ԫ�غʹ���Ŀ��ֵ�����ƶ�βָ��
            if(numbers[startIndex]+numbers[endIndex]>target){
                endIndex--;

            //���ͷβָ��ָ���Ԫ�غ�С��Ŀ��ֵ�����ƶ�ͷָ��
            }else if(numbers[startIndex]+numbers[endIndex]<target){
                startIndex++;

            //���ͷβָ��ָ���Ԫ�غ͵���Ŀ��ֵ����ͷβָ��push�����������
            }else{
                result.push_back(startIndex+1);
                result.push_back(endIndex+1);
                break;
            }
        }
        return result;
    }
};