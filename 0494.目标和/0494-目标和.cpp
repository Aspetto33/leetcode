/*
 *假设加法的总和是x，则减法的总和是数组元素总和sum-x；
 *则加法和减去减法的和应该等于目标值，即x-（sum-x）=target
 *所以当加法总和等于（sum+target）/2时，恰好能达到target
 *此时应该求有多少种方法可以达到放满容量为x的背包
*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i = 0;i<nums.size();i++) sum+=nums[i];

        //如果两者的和不是偶数的话，是达不到要求的，因为数组元素都是整数
        if((sum+target)%2==1) return 0;
        
        //如果目标值大于数组元素总和，同样达不到
        if(abs(target)>sum) return 0;

        //加法总和，即放满容量为bigSize的背包
        int bigSize = (sum+target)/2;

        vector<int> dp(bigSize+1,0);
        dp[0] = 1;  //装满容量为0的背包有1种方法，即什么也不装

        for(int i = 0;i<nums.size();i++){
            for(int j = bigSize;j>=nums[i];j--){
                dp[j]+=dp[j-nums[i]];   //递推公式，值累加
            }
        }
        return dp[bigSize];
    }
};