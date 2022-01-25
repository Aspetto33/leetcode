/*
 *判断数组部分元素总和是否可以达到所有元素总和的一半
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;    //记录所有元素总和

        vector<int> dp(10001,0);    //记录总和
        for(int i = 0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2==1) return false;  //如果和为奇数肯定分不成两个和相同的数组
        int target = sum/2;
        for(int i = 0;i<nums.size();i++){
            for(int j = target;j>=nums[i];j--){
                dp[j] = max(dp[j],dp[j-nums[i]]+nums[i]);
            }
        }
        if(dp[target] == target) return true;
        return false;
    }
};