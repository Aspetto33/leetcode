
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        //当数组是一个或者0ge元素的时候，直接返回数组大小
        if(nums.size()<=1) return nums.size();
        int curDiff = 0;    //记录当前前后数的差
        int preDiff = 0;    //记录前一个差
        int result = 1;     //记录结果，默认最后有一个摆动序列
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