class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;   //������
        int right = nums.size() - 1;    //������

        //ѭ����������Ҫ�е��ڣ���Ϊ������ֻ��һ��Ԫ�أ���targetǡ�������ֵʱ����������
        while(left<=right){
            int middle = (left+right)/2;    //�м�����

            //��targetС���м�������Ӧֵ��������ֵ��Ϊ�м�ֵǰ�������
            if(target<nums[middle]){
                right = middle - 1;

            //��target�����м�������Ӧֵ��������ֵ��Ϊ�м�ֵ���������
            }else if(target>nums[middle]){
                left = middle + 1;

            //ǡ�õ���ʱ����
            }else{
                return middle;
            }
        }

        //û�з���������ֵ������-1
        return -1;
    }
};