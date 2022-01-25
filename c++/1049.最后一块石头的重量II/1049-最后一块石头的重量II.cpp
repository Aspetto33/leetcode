class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        vector<int> dp(1501,0);  //初始化dp数组
        int sum = 0;    //记录stones数组元素总和
        for(int i = 0;i<stones.size();i++) sum+=stones[i];
        int target = sum/2; //向下取整 
        for(int i = 0;i<stones.size();i++){
            for(int j = target;j>=stones[i];j--){
                dp[j] = max(dp[j],dp[j-stones[i]]+stones[i]);
            }
        }
        return (sum-dp[target])-dp[target];

    }
};