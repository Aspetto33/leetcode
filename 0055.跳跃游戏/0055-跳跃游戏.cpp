class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;  //��¼ÿ���ط������ߵ������
        for(int i=0;i<=cover;i++){
            //��Ϊ��ǰ�Ѿ���iλ���ˣ�����Ҫ����i�жϵ�ǰλ�ÿ��������ߵĲ����Ƿ���Ե����յ�
            cover = max(i+nums[i],cover);
            if(cover>=nums.size()-1){
                return true;
            }
        }
        return false;
    }
};