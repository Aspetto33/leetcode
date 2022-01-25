
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        //��������һ������0geԪ�ص�ʱ��ֱ�ӷ��������С
        if(nums.size()<=1) return nums.size();
        int curDiff = 0;    //��¼��ǰǰ�����Ĳ�
        int preDiff = 0;    //��¼ǰһ����
        int result = 1;     //��¼�����Ĭ�������һ���ڶ�����
        for(int i=0;i<nums.size()-1;i++){
            curDiff = nums[i+1] - nums[i];
            if(curDiff>0&&preDiff<=0 || preDiff>=0&&curDiff<0){
                result++; 
                preDiff = curDiff;
            }
            
        }
        return result;
    }
};