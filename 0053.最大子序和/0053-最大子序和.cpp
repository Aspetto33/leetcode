class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];   //记录结果的变量赋初始值为数组第一个元素的值
        int sum = 0;    //记录数组元素和的值
        for(int i = 0;i< nums.size();i++){
            //当sum>0的时候保证可以继续向下加数组元素值
            if(sum>0){
                sum+=nums[i];
            //当sum<=0的时候此时肯定不满足最大和，所以重置子序列的第一个元素
            }else{
                sum = nums[i];
            }
            result = max(result,sum);   //每次比较将较大值赋给result，以保证返回的是最大值
        }
        return result;
    }
};