class Solution {
public:
    /*
     *�����ٶ���ռ䣬�������
     *0����������������Ϊ��������
     *�����������Ϊ0
    */
    int singleNumber(vector<int>& nums) {
        int result = 0;
        
        //���
        for(int num:nums){
            result = result^num;
        }

        return result;
    }
};