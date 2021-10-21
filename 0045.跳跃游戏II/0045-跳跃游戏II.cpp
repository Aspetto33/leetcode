class Solution {
public:
    int jump(vector<int>& nums) {
        int max_far = 0;    //��¼��ǰԪ��ָ����������ߵ������
        int step = 0;   //��¼�����յ��ߵĲ���
        int end = 0;   //��¼��ǰԪ��ָ������ı߽�
        //�����������ڶ���Ԫ�أ���Ϊ�϶��ɴ������󵽴��λ��һ�������һ��Ԫ�ص�λ�û��ߺ���
        for(int i=0;i<nums.size()-1;i++){
            max_far = max(nums[i]+i,max_far);   //���϶Ա��������ĸ�Ԫ�ظ���
            //���ָ��i�ߵ�����߽磬step��Ҫ��1
            if(i == end){
                step++;
                end = max_far;
            }
        }
        return step;
    }
};