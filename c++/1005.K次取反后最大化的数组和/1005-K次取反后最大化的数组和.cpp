/*
 *  ���Ƚ����鰴�վ���ֵ��С�Ӵ�С����
 *  Ȼ��ֵС��0������Ϊ��ֵ���ҽ�k��1
 *  ������kʣ�µ���ż�����൱��ʣ�µ�������������Ϊ�����ٱ�Ϊ��������˿��Բ��ù�
 *  ���ʣ�µ���������������֮����������һ��Ԫ�ر�Ϊ����
*/
class Solution {
static bool cmp(int a,int b){
    return abs(a)>abs(b);
}
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),cmp);
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0&&k>0){
                nums[i]*=-1;
                k--;
            }
        }
        if(k%2==1) nums[nums.size()-1]*=-1; //���kΪ����������С��ֵ��Ϊ����
        int result = 0; //��¼���ĺ�
        for(int num:nums){
            result+=num;
        }
        return result;
    }
};